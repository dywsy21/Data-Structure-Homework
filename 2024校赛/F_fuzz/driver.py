import random
import subprocess

def generate_test_case():
    n = random.randint(1, 5)
    c = random.randint(1, 10)
    a = [random.randint(1, 10) for _ in range(n)]
    b = [random.randint(1, 10) for _ in range(n)]
    return n, c, a, b

def run_program(program, n, c, a, b):
    input_data = f"{n} {c}\n" + " ".join(map(str, a)) + "\n" + " ".join(map(str, b)) + "\n"
    result = subprocess.run(program, input=input_data, text=True, capture_output=True)
    return result.stdout.strip()

def main():
    while True:
        n, c, a, b = generate_test_case()
        result_brute = run_program("./F_brute.exe", n, c, a, b)
        result_optimized = run_program("./F.exe", n, c, a, b)
        
        if result_brute != result_optimized:
            print(f"Test case failed:\n n={n}, c={c}, a={a}, b={b}")
            print(f"Brute force result: {result_brute}")
            print(f"Optimized result: {result_optimized}")

if __name__ == "__main__":
    main()
