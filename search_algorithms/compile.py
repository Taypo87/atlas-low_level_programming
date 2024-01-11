import sys
import subprocess

# Get all arguments except the first one (script name)
files = sys.argv[1:]

for file in files:
    # Assuming gcc and file.c -> file (executable)
    output_file = file.rsplit('.c', 1)[0]
    # Compile command
    subprocess.run(['gcc', file, '-o', output_file, '-Wall', '-Werror', '-Wextra', '-pedantic'])
    print(f"Compiled {file} into {output_file}")
