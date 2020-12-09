from sys import argv
source = argv[1] if len(argv) == 2 else exit(0)
SIZE = 1000
stack = []
data = [0 for _ in range(SIZE)]
l = len(source)
i = ignore = pos = 0
while i < l:
	c = source[i]
	if c == '[':
		stack.append(i)
		if data[pos] == 0 and ignore == 0: ignore = len(stack)
	elif c ==']':
		last = stack.pop()
		if ignore == len(stack)+1 or ignore == 0:
			ignore = 0
			if data[pos] != 0: i = last-1
	elif ignore != 0: pass
	elif c == '.': print(chr(data[pos]), end='')
	elif c == ',': data[pos] = ord(t[0]) if (t:=input()) else 0
	elif c == '>': pos = (pos + 1) % SIZE
	elif c == '<': pos = (pos - 1) % SIZE
	elif c == '+': data[pos] += 1
	elif c == '-': data[pos] -= 1
	i += 1
