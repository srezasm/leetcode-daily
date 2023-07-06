#!/bin/bash

# Get the file ID
if [ -n "$1" ]; then
  file_id="$1"
else
  echo "Enter the file ID: "
  read file_id
fi

# Find the file that starts with the integer ID
file_name=$(find . -name "${file_id}.*.cpp")

# Add "//" + date -I  \n\n to the start of the file
timestamp=$(date -I)
sed -i "1i // ${timestamp}\n" "${file_name}"

# Replace "// @lc code=start" with "using namespace std;"
sed -i 's/\/\/ @lc code=start/using namespace std;\n/g' "${file_name}"

# Remove "// @lc code=end" from the file content
sed -i '/\/\/ @lc code=end/d' "${file_name}"

# Move file to current month directory
mv $file_name $(date +%Y-%m)