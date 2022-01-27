# declaring a string variable
str = "Amdani athani kharcha rupaiya."

# declaring an empty string variable for storing modified string
modified_str = ''

# iterating over the string
for char in range(0, len(str)):
	# checking if the character at char index is equivalent to 'a'
	if(str[char] == 'a'):
		# append $ to modified string
		modified_str += '@'
	else:
		# append original string character
		modified_str += str[char]

print("Modified string : ")
print(modified_str)
