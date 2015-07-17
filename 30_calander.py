#  Calendar 
# Get a date (mon/day/year) from user. Printexact the week of dates (Sun to Sat). ex) input: 
# 2/20/2001 if the day is Wednesday  
# output: Sunday 2/17/2001  
# Monday 2/18/2001   
# Tuesday 2/19/2001  
# Wednesday 2/20/2001  
# Thursday 2/21/2001  
# Friday 2/22/2001  
# Saturday 2/23/2002 


import time
import datetime


weeklist = ['Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday']

def print_datalist(str,weekday):
	current_obj = datetime.datetime.strptime(str,'%m/%d/%Y')
	res = []
	index =weeklist.index(weekday)
	for i in range(1,index+1):
		tmp = current_obj - datetime.timedelta(days = index-i+1)
		#a = tmp.strftime('%m/%d/%Y')
		#print a
		res.append(tmp)
	res.append(current_obj)
	for i in range(1,7-index):
		tmp = current_obj - datetime.timedelta(days = i*-1)
		res.append(tmp)
	
	res = map(lambda x:x.strftime('%m/%d/%Y'),res)
	for i in range(7):
		res[i] += ":"+weeklist[i]
	for i in res:
		print i

print_datalist("2/20/2012","Tuesday")


