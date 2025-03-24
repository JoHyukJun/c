# Chart Application

This application is a simple GTK4-based program that displays a line chart with random values that update every second. The application is designed to run on macOS.

## Prerequisites

Before you can build and run this application, you need to have the following installed on your macOS system:

1. **Homebrew**: A package manager for macOS. You can install it from [Homebrew](https://brew.sh/).

2. **GTK4**: You can install GTK4 using Homebrew.

3. **pkg-config**: A helper tool used when compiling applications and libraries.

4. **GCC**: The GNU Compiler Collection.

To install the necessary dependencies, run the following commands in your terminal:

```sh
# Install Homebrew if not already installed
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install GTK4
brew install gtk4

# Install pkg-config
brew install pkg-config

# Install GCC
brew install gcc
