 #!/usr/bin/python

 import os

 file_list = os.listdir("./data/")

 apps = ["evince", "xpdf"]

 fuzz_output = "fuzz.pdf"

 FuzzFactor = 20
 num_tests = 200

 import math
 import random
 import string
 import subprocess
 from subprocess
 import Popen, PIPE
 import time
 f = 0

 #if len(file_list) > 100:
     # random.shuffle(file_list)
 # file_list = file_list[0: 100]

 for file_choice in file_list:
     f += 1
 os.system("echo " + str(f) + " of " + str(len(file_list)) + " > ./counter")
 for i in range(num_tests):
     os.system("chmod 666 " + fuzz_output)

 buf = bytearray(open("./data/" + file_choice, 'rb').read())

 numwrites = random.randrange(math.ceil((float(len(buf)) / FuzzFactor))) + 1

 for j in range(numwrites):
     rbyte = random.randrange(256)
 rn = random.randrange(len(buf))
 buf[rn] = "%c" % (rbyte)

 open(fuzz_output, 'wb').write(buf)

 os.system("chmod 444 " + fuzz_output)

 for app in apps:
     print app + " - " + fuzz_output
 process = subprocess.Popen([app, fuzz_output])
 processPID = process.pid

 time.sleep(1)

 crashed = process.poll()
 if not crashed:
     try:
     process.terminate()
 except OSError:
     print "Process self-terminated."

 p0 = subprocess.Popen(["dmesg"], stdout = PIPE)
 p1 = subprocess.Popen(["tail"], stdin = p0.stdout, stdout = PIPE)
 p2 = subprocess.Popen(["grep", str(processPID)], stdin = p1.stdout, stdout = PIPE)
 p0.stdout.close()
 p1.stdout.close()
 output = p2.communicate()[0]

 if len(output) > 0:
     print "Success - a crash!!!"
 timestamp = time.time()
 os.system("dmesg | grep " + str(processPID) + " >> " + str(timestamp) + ".log")
 os.system("cp fuzz.pdf ./crashPDF/" + str(timestamp) + ".pdf")

 terminated = process.poll()
 if not terminated:
     os.system("pkill " + app)
