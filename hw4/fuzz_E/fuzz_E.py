import threading
import subprocess
import random
import string
import os

# 用于存储找到的不一致的结果
found_discrepancy = False
discrepancy_data = None

# 线程锁，用于同步
lock = threading.Lock()

def generate_random_input():
    """生成随机输入数据"""
    T = random.randint(1, 10)  # 测试用例的数量
    input_data = [str(T)]
    
    for _ in range(T):
        length = random.randint(1, 20)
        s = ''.join(random.choices(string.ascii_lowercase + string.ascii_uppercase, k=length))
        input_data.append(s)
    
    return '\n'.join(input_data)

def run_program(executable, input_data):
    """运行程序并获取输出"""
    try:
        result = subprocess.run([executable], input=input_data, text=True, capture_output=True, timeout=5)
        return result.stdout.strip()
    except subprocess.TimeoutExpired:
        return None  # 超时处理

def compare_outputs(input_data):
    """运行两个程序并比较输出"""
    global found_discrepancy, discrepancy_data
    
    if found_discrepancy:  # 如果已经找到不一致，直接返回
        return
    
    output_correct = run_program('./E_correct.exe', input_data)
    output_erroneous = run_program('./E.exe', input_data)
    
    if output_correct is None or output_erroneous is None:
        return  # 如果有一个程序超时，跳过
    
    if output_correct != output_erroneous:
        with lock:
            if not found_discrepancy:
                found_discrepancy = True
                discrepancy_data = (input_data, output_correct, output_erroneous)

def worker_thread():
    """线程工作函数，生成随机输入并比较输出"""
    while not found_discrepancy:
        input_data = generate_random_input()
        compare_outputs(input_data)

def main():
    threads = []
    num_threads = 400  # 创建128个线程
    
    # 启动线程
    for _ in range(num_threads):
        t = threading.Thread(target=worker_thread)
        t.start()
        threads.append(t)
    
    # 等待所有线程完成
    for t in threads:
        t.join()
    
    # 如果找到不一致，写入日志文件并关机
    if discrepancy_data:
        input_data, output_correct, output_erroneous = discrepancy_data
        log_message = (
            "Discrepancy found!\n"
            f"Input:\n{input_data}\n\n"
            f"E_correct.exe output:\n{output_correct}\n\n"
            f"E.exe output:\n{output_erroneous}\n"
        )
        
        # 写入日志文件
        with open('discrepancy_log.txt', 'w') as log_file:
            log_file.write(log_message)
        
        print("Discrepancy found and logged. Shutting down...")
        
        # 系统关机命令 (对于 Windows 和 Linux/Mac 需要不同命令)
        if os.name == 'nt':  # Windows
            os.system('shutdown /s /t 1')  # 立即关机
        else:  # Linux/Unix/Mac
            os.system('shutdown -h now')  # 立即关机
    else:
        print("No discrepancies found.")

if __name__ == "__main__":
    main()
