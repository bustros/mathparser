#!/usr/bin/env python3
import subprocess
import os
import sys
from pathlib import Path

def format_cpp_files(directory):
    """Format all .cpp and .hpp files in the given directory using clang-format."""
    if not os.path.isdir(directory):
        print(f"Error: {directory} is not a valid directory")
        return False
    
    cpp_files = list(Path(directory).rglob("*.cpp")) + list(Path(directory).rglob("*.hpp"))
    if not cpp_files:
        print(f"No .cpp or .hpp files found in {directory}")
        return False

    try:
        # Check if clang-format is installed
        subprocess.run(["clang-format", "--version"], check=True, capture_output=True)
    except subprocess.CalledProcessError:
        print("Error: clang-format is not installed")
        return False
    except FileNotFoundError:
        print("Error: clang-format not found. Please install clang-format")
        return False

    success = True
    for file_path in cpp_files:
        try:
            print(f"Formatting {file_path}")
            subprocess.run(["clang-format", "-i", "-style=file", str(file_path)], check=True)
        except subprocess.CalledProcessError as e:
            print(f"Error formatting {file_path}: {e}")
            success = False

    return success

if __name__ == "__main__":
    directory = sys.argv[1] if len(sys.argv) > 1 else "."
    success = format_cpp_files(directory)
    sys.exit(0 if success else 1)