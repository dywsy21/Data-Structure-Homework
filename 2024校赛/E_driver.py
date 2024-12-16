import subprocess
import random

def generate_test_data(n):
    # 1000000000
    return [random.randint(1, 32) for _ in range(n)]

def write_test_data_to_file(filename, data):
    with open(filename, 'w') as f:
        f.write(f"{len(data)}\n")
        f.write(" ".join(map(str, data)) + "\n")

def run_executable(input_file, output_file):
    with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
        subprocess.run(["E.exe"], stdin=infile, stdout=outfile)

def validate_output(output):
    lines = output.strip().split('\n')
    count = int(lines[-1])
    for line in lines[:-1]:
        s, t = map(int, line.split())
        if t != s + 1 and t != s + 2 and t != s + 3:
            return False
    return True

def main():
    while True:
        n = random.randint(1, 1000)  # Generate a random number of elements
        test_data = generate_test_data(n)
        input_file = "input.txt"
        output_file = "output.txt"
        
        write_test_data_to_file(input_file, test_data)
        print(f"Running test with {n} elements")
        run_executable(input_file, output_file)
        
        with open(output_file, 'r') as f:
            output = f.read()
            # print(output)
            if not validate_output(output):
                print("Validation failed")
                break

if __name__ == "__main__":
    main()
