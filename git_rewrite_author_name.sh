#!/bin/sh

# Usage is ./git_rewrite_author_name <Repo name> <Old email> <New email>

repo="$1"
old_email="$2"
new_email="$3"

git clone --bare git@github.com:karthick1987/$repo\.git
cd $repo\.git

cp ../change_author_email\.sh \. 

. change_author_email\.sh "$old_email" "$new_email"

git push --force --tags origin 'refs/heads/*'
