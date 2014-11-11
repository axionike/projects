# Reddit dailyprogrammer challenge
# easy2.py
# Life expectancy calculator

#! /usr/bin/python
import time
import sys

print """
	Hi, this calculator will estimate your life expectancy
	given your gender and current age. (Based off US life expectancy)
	"""


print "Are you male or female?"
print "1) Male"
print "2) Female"
gender = raw_input("Choose option 1 or 2: ")

currentage = float(raw_input("How old are you (in years)?"))

print "Calculating....\n"
time.sleep(3);

femalelife = 82.2
malelife = 77.4

if gender == "1":
	yearleft = malelife - currentage
	monthleft = yearleft * 12
	daysleft = yearleft * 365 + (yearleft / 4)
	hoursleft = daysleft * 24
	minutesleft = hoursleft * 60
	secondsleft = minutesleft * 60

elif gender == "2":
	yearleft = femalelife - currentage
	monthleft = yearleft * 12
	daysleft = yearleft * 365 + (yearleft / 4)
	hoursleft = daysleft * 24
	minutesleft = hoursleft * 60
	secondsleft = minutesleft * 60

else:
	print "You didn't enter a valid gender... :("
	sys.exit()

print """
Based on estimates by the World Health Organization,
and without considering other factors, if you were to
live to the average life expectancy for somebody of your
gender, this is how much longer you have to live.
Have a nice day!
"""

print "Years: 		%d" % yearleft
print "Months: 		%d" % monthleft
print "Days: 		%d" % daysleft
print "Hours: 		%d" % hoursleft
print "Minutes: 	%d" % minutesleft
print "Seconds: 	%d" % secondsleft


