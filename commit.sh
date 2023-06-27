#!/bin/bash

# Ask to remove compiled files
find . -maxdepth 2 -type f -executable -regex '.*/[0-9].*[0-9]/[0-9][^.]*[.][^./]*$' -exec rm -i "{}" +
find . -maxdepth 2 -type f -executable -regex '.*.out$' -exec rm -i "{}" +

# Ask for leetcode problem number
read -p "Enter leetcode problem number: " problem_number

# Show git status and ask for confirmation
git status
read -p "Do you want to continue? [Y/n] " confirmation

if [[ "$confirmation" =~ ^[Nn]$ ]]; then
    echo "Aborting."
    exit 1
fi

# Commit changes
git add .
git commit -m "problem $problem_number"

# Push to origin main
git push origin main