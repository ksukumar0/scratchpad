set can-use-hw-watchpoints 0
define asst2
dir /Users/Ck/Documents/Projects/scratchpad/os161_syscalls/kern/compile/ASST2

target remote localhost:16161
b panic
end
