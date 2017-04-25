#!/usr/bin/env python

from time import sleep
import random


ilk_part    = "ABCDEFGHIJKLMNOP"
ikinci_part = "1234567890"
son_part    = "pqrstuvwxyz"

tire = '-'

while True:
	key = ""
	#ilk part
	for i in range(4):
		key += random.choice(ilk_part)
	
	key += tire

	#ikinci part
	for i in range(3):
		key += random.choice(ikinci_part)

	key += tire

	#son part
	for i in range(3):
		key += random.choice(son_part)

	print key
	sleep(1)





