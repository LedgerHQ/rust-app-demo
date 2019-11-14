import subprocess
import os

BOLOS_SDK = os.environ.get("BOLOS_SDK")
if BOLOS_SDK is None:
  BOLOS_SDK = "./nanos-secure-sdk/"

icon = subprocess.run(
  [
    "python",
    BOLOS_SDK+"icon.py",
    "rust.gif",
    "hexbitmaponly"
    ], check=True, stdout=subprocess.PIPE)

iconhex = icon.stdout

subprocess.run(["cargo", "objcopy", "--bin", "rust-app-demo", "--release", "--", "-O", "ihex", "-S", "app.hex"], check=True)

subprocess.run(
  [
    "python",
    "-m",
    "ledgerblue.loadApp",
    "--curve",
    "secp256k1",
    "--tlv",
    "--targetId",
    "0x31100004",
    "--delete",
    "--fileName",
    "./app.hex",
    "--appName",
    "tRustMe",
    "--appVersion",
    "\"0.1\"",
    "--dataSize",
    "0",
    "--icon",
    iconhex.decode()
  ])
