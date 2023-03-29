# Amonbit

Copyright (c) 2023 The Amonbit Project. 

## Table of Contents

  - [Development resources](#development-resources)
  - [Introduction](#introduction)
  - [About this project](#about-this-project)
  - [Supporting the project](#supporting-the-project)
  - [License](#license)
  - [Contributing](#contributing)
  - [Release staging schedule and protocol](#release-staging-schedule-and-protocol)
  - [Compiling Amonbit from source](#compiling-amonbit-from-source)
    - [Dependencies](#dependencies)
    - [Gitian builds](#gitian-builds)
  - [Internationalization](#Internationalization)
  - [Using Tor](#using-tor)
  - [Pruning](#Pruning)
  - [Debugging](#Debugging)
  - [Known issues](#known-issues)

## Development resources

- Mail: [agastronics.dev@gmail.com](mailto:agastronics.dev@gmail.com)
- GitHub: [https://github.com/amonbit-project/amonbit](https://github.com/amonbit-project/amonbit)
- IRC: [#amonbit-dev on Discord](https://discord.gg/8nUbx6yc)
- It is HIGHLY recommended that you join the #Amonbit-dev IRC channel if you are developing software that uses Amonbit. Due to the nature of this open source software project, joining this channel and idling is the best way to stay updated on best practices and new developments in the Amonbit ecosystem. All you need to do is join the IRC channel and idle to stay updated with the latest in Amonbit development. If you do not, you risk wasting resources on developing integrations that are not compatible with the Amonbit network. The Amonbit core team and community continuously make efforts to communicate updates, developments, and documentation via other platforms – but for the best information, you need to talk to other Amonbit developers, and they are on IRC. #amonbit-dev is about Amonbit development, not getting help about using Amonbit, or help about development of other software, including yours, unless it also pertains to Amonbit code itself. For these cases, checkout #Amonbit.

## Introduction

Amonbit is a private, secure, untraceable, decentralised digital currency and asset management. You are your bank, you control your funds, and nobody can trace your transfers unless you allow them to do so.

**Privacy:** Amonbit uses a cryptographically sound system to allow you to send and receive funds without your transactions being easily revealed on the blockchain (the ledger of transactions that everyone has). This ensures that your purchases, receipts, and all transfers remain private by default.

**Security:** Using the power of a distributed peer-to-peer consensus network, every transaction on the network is cryptographically secured. Individual wallets have a 25-word mnemonic seed that is only displayed once and can be written down to backup the wallet. Wallet files should be encrypted with a strong passphrase to ensure they are useless if ever stolen.

**Untraceability:** By taking advantage of ring signatures, a special property of a certain type of cryptography, Amonbit is able to ensure that transactions are not only untraceable but have an optional measure of ambiguity that ensures that transactions cannot easily be tied back to an individual user or computer.

**Decentralization:** The utility of Amonbit depends on its decentralised peer-to-peer consensus network - anyone should be able to run the Amonbit software, validate the integrity of the blockchain, and participate in all aspects of the Amonbit network using consumer-grade commodity hardware. Decentralization of the Amonbit network is maintained by software development that minimizes the costs of running the Amonbit software and inhibits the proliferation of specialized, non-commodity hardware.
