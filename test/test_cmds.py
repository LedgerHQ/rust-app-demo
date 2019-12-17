# For speculos
from ledgerblue.commTCP import getDongle
# anything else (normal device)
# from ledgerblue.comm import getDongle

from binascii import hexlify,unhexlify

CMDS = [
    "800100aabbaabb",
    "800200aabbaabb",
    "80032000" + "aa"*32,
    "80032000" + "bb"*32,
    "7700",
    "806600",
    "FF00",
    "8003ff02" + "cc"*32,
]

d = getDongle(port=1237, debug=True)
for cmd in map(unhexlify,CMDS):
    r = None 
    try:
        r = d.exchange(cmd, 2)
    except Exception as e:
        print(e)
    if r is not None: 
        print("Response : ", hexlify(r))
