a = "1000"
b = "115"

# Get the length diff
if len(a) > len(b):
    lenDiff = len(a) - len(b)
    for i in reversed(range(len(a))):
        print(f'')
elif len(b) > len(a):
    lenDiff = len(b) - len(a)
