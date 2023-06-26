#!/bin/bash

# Step 1: Get the file ID
echo "Enter the file ID: "
read file_id

# Step 2: Find the file that starts with the integer ID
file_name=$(find . -name "${file_id}*.cpp")

# Step 3: Add "//" + date -I  \n\n to the start of the file
timestamp=$(date -I)
sed -i "1i // ${timestamp}\n" "${file_name}"

# Step 4: Remove "// @lc code=start" from the file content
sed -i '/\/\/ @lc code=start/d' "${file_name}"

# Step 5: Remove "// @lc code=end" from the file content
sed -i '/\/\/ @lc code=end/d' "${file_name}"