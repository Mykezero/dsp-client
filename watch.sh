#!/bin/bash

# Run make every .5 seconds after file changes
watch -n .5 -x make && ./a.out
