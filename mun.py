# a typical program that helps to calculate
# pending tax in my father's office.

from datetime import datetime

print "\nWhat is the Quarterly Tax?"
tax = int(raw_input("TAX (INR): "))

print "\nWhat is the Rate of Interest?"
rate = int(raw_input("RATE (p.p.a): "))

print "\nDue from which year?"
due_year = int(raw_input("YEAR: "))

print "\nDue starting from which month? Choose the option."
print "  1) JAN   2) FEB   3) MAR"
print "  4) APR   5) MAY   6) JUN"
print "  7) JUL   8) AUG   9) SEP"
print " 10) OCT  11) NOV  12) DEC"
due_mnth = int(raw_input("\nMONTH: "))

present_year = datetime.now().year
present_mnth = datetime.now().month
total_mnth = ((((present_year - due_year) * 12) + present_mnth) - due_mnth)
tot_quat = (((total_mnth - 1) / 3) + 1)
totl_mnthly = (tot_quat / 2) * (1 + total_mnth)
tot_int = ((rate * totl_mnthly * tax) / 100)

print "\nTOTAL PRINCIPAL: %d" % (tax * tot_quat)
print "TOTAL INTEREST: %d" % tot_int

raw_input("\nPRESS ENTER TO EXIT...")