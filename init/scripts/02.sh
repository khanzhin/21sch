#!/bin/bash

w | awk '{print$1}'

echo 'who should i kill?'

read killuser

killall -u $killuser && userdel -f $killuser
