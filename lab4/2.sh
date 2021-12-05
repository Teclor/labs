#!/bin/bash
# первый столбец - имя группы, 4й (последний) - список пользователей-членов группы
userFromArg=$1
if [ -n "$userFromArg" ]; then
  usersInSameGroups=$(grep "$userFromArg" /etc/group | cut -d: -f4)
  echo "List of users in the same groups as ${userFromArg}:"
  totalUserCount=0
  for users in $usersInSameGroups; do
    if [ -n "$users" ]; then
      IFS=','
      usersArray=($users)
      unset IFS
      for user in "${usersArray[@]}"; do
        if [[ -n "$user" && "$user" != "$userFromArg" ]]; then
          echo "$user"
          ((totalUserCount++))
        fi
      done
    fi
  done
  echo "Total users in the same groups: $totalUserCount."
else
  echo "Please, put the user name as the first argument."
fi
