import sys

def get_contents(file_name):
	with open(file_name) as f:
	    content = f.readlines()
	# you may also want to remove whitespace characters like `\n` at the end of each line
	content = [x.strip() for x in content]
	return content

if __name__ == '__main__':
	file1, file2 = sys.argv[1], sys.argv[2]

	content1 = get_contents(file1)
	content2 = get_contents(file2)

	for i in range(len(content1)):
		if(content1[i] != content2[i]):
			sys.exit(str(content1[i]) + ' != ' + str(content2[i]) + \
				'\n' + 'Answer doesn\'t match' )
	print 'Correct answer'

