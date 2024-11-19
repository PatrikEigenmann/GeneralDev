# Network Utilities

## Description
This folder contains a collection of utilities and console applications designed for network administration tasks. These tools can be invaluable for network administrators.

## Tools

### chkip
The `chkip` program is used to ping hosts within a specified network range to determine which hosts are online.

#### Usage
chkip "192.168.1.?"
This command will check the network range from `192.168.1.1` to `192.168.1.254` to find online hosts.

#### chkip.makefile
The `chkip.makefile` is a makefile designed for our cross-platform pmake tool. It provides specific compiler instructions to compile the `chkip.c` program.

## Installation
To compile any tool within this folder, ensure you have our cross-platform pmake tool installed. Each tool has its own makefile which provides specific compiler instructions. Use the corresponding makefile to compile the tool.

## Contributing
If you have any network utilities or enhancements you'd like to add to this collection, please feel free to submit a pull request. Contributions are welcome!

## License
This project is licensed under the GNU General Public License. See the LICENSE file for more details.
