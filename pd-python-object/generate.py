import random

x = 5
s = 1

def get_random_note():
	return random.randint(1, 7)

def get_sequence():
	r = s
	s = s + 1
	return r
