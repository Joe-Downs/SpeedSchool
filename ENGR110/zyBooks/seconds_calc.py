seconds = int(input())
original_seconds = seconds
minutes = 0
hours = 0
days = 0
if seconds % 86400 != 0:
    days = int(seconds / 86400)
    seconds -= (days * 86400)
    if seconds % 3600 != 0:
        hours = int(seconds / 3600)
        seconds -= (hours * 3600)
        if seconds % 60 != 0:
            minutes = int(seconds / 60)
            seconds -= (minutes * 60)
        else:
            minutes = int(seconds / 60)
    else:
        hours = int(seconds / 3600)
else:
    days = int(seconds / 86400)
        
print(str(original_seconds) + " seconds is equivalent to " + str(days) + " day(s), " + str(hours) + " hour(s), " + str(minutes) + " minute(s), and " + str(seconds) + " second(s).") 
