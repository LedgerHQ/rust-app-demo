# For speculos
from ledgerblue.commTCP import getDongle
# anything else (normal device)
# from ledgerblue.comm import getDongle

from binascii import hexlify,unhexlify

CMDS = [
    # "800100aabbaabb",
    # "800200aabbaabb",
    "8004",
    # "80032000" + "aa"*32,
    # "80032000" + "bb"*32,
    # "7700",
    # "806600",
    # "FF00"
]

d = getDongle(debug=True)
for cmd in map(unhexlify,CMDS):
    r = b'' 
    try:
        r = d.exchange(cmd, 2)
    except Exception as e:
        print(e)
    print("Response : ", hexlify(r))
