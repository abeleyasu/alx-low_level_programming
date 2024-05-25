#!/bin/bash

# Set up LD_PRELOAD to inject the shared library
export LD_PRELOAD=./101-make_me_win.so

# Clean up the shell script after execution
rm "$0"
