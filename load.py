import subprocess

subprocess.run(["cargo", "objcopy", "--bin", "rust-app-demo", "--release", "--", "-O", "ihex", "-S", "app.hex"], check=True)

subprocess.run(
  [
    "python",
    "-m",
    "ledgerblue.loadApp",
    # "--apdu",
    "--path",
    "2147483692/2147483776",
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
  ])