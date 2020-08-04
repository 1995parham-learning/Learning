# Shell
## [chert-2-1](chert-2/chert-2-1.sh)
Print the names and determine the number of files in /bin directory whose
first letter is ‘c’.

## [chert-2-2](chert-2/chert-2-2.sh)
Print the names of the first 7 files of /etc directory.

## [chert-2-3](chert-2/chert-2-3.sh)
Print the names and determine the number of files of /etc directory that
contain ‘z’.

## [chert-2-4](chert-2/chert-2-4.sh)
Print 10 commands of /bin sorting by the last access time.

## [chert-2-5](chert-2/chert-2-5.sh)
Create a file containing the names of the first 7 files and the last 6 files of
/etc directory, in alphabet order.

## [chert-2-6](chert-2/chert-2-6.sh)
Print the name of 8 files in /usr/sbin/ sorting by the last modification time.

## [chert-2-7](chert-2/chert-2-7.sh)
Create a file in /home/directory1, write "hello world !" in it and copy it to a
new /home/directory2. Finally, remove it from directory1.

## [power](power.sh)
Do you want integer power function in bash 🙈
```sh
power.sh 10 2
```

## Useful Examples
1. List all Go packages that are belong to 1995parham in evey sub directories' go and go.mod files.

```sh
grep -E "github.com/1995parham/.*" **/*.go **/go.mod
```

2. Remove all Go's package prefix in evey sub directories' go and go.mod files.

```sh
sed -e "s#github.com/1995parham/Learning/[Gg]o/##g" -i **/*.go **/go.mod
```
