#!/bin/bash

echo -e "\033[0;32mDeploying updates to GitHub...\033[0m"

# Build the project.
hugo -t black-and-light 

# Go To Public folder
cd public
# Add changes to git.
git add .

# Commit changes.
msg="rebuilding site `date`"
if [ $# -eq 1 ]
    then msg="$1"
fi
git commit -m "$msg"

#do a pull first
git pull

# Push source and build repos.
git push origin master

# Come Back up to the Project Root
cd ..
