#!/bin/bash
valgrind --leak-check=full --show-leak-kinds=all output/main
