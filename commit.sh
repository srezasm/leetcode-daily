#!/bin/bash

# Ask to remove compiled files
find . -maxdepth 2 -type f -executable -regex '.*/[0-9].*[0-9]/[0-9][^.]*[.][^./]*$' -exec rm -i "{}" +
find . -maxdepth 2 -type f -executable -regex '.*.out$' -exec rm -i "{}" +

# Ask for leetcode problem number
if [ -n "$1" ]; then
  problem_number="$1"
else
  echo "Enter leetcode problem number: "
  read problem_number
fi

# Stage changes
git add $(date +%Y-%m)/$problem_number.*.cpp

# Show git status and ask for confirmation
git status
read -p "Do you want to continue? [Y/n] " confirmation

if [[ "$confirmation" =~ ^[Nn]$ ]]; then
    echo "Aborting."
    exit 1
fi

# Commit
git commit -m "problem $problem_number"

# Push to origin main
git push origin main