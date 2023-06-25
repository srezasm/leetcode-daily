#!/bin/bash

# Step 1: Ask for leetcode problem number
read -p "Enter leetcode problem number: " problem_number

# Step 2: Show git status and ask for confirmation
git status
read -p "Do you want to continue? [Y/n] " confirmation

if [[ "$confirmation" =~ ^[Nn]$ ]]; then
    echo "Aborting."
    exit 1
fi

# Step 3: Commit changes
git add .
git commit -m "problem $problem_number"

# Step 4: Push to origin main
git push origin main