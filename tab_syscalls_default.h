/*
** tab_syscalls_default.h for  in /home/gayot_o/dev/tek2/strace
** 
** Made by olivier gayot
** Login   <gayot_o@epitech.net>
** 
** Started on  Sat May 18 17:09:48 2013 olivier gayot
** Last update Sat May 18 17:09:48 2013 olivier gayot
*/

#ifndef GENERATED_H
#define GENERATED_H

{3, "read", INT, {INT, ADDR,  INT, 0, 0, 0}},
{3, "write", INT, {INT, ADDR,  INT, 0, 0, 0}},
{2, "open", INT, {STRING,  INT, 0, 0, 0, 0}},
{1, "close", INT, {INT, 0, 0, 0, 0, 0}},
{2, "stat", INT, {STRING, ADDR, 0, 0, 0, 0}},
{2, "fstat", INT, {INT, ADDR, 0, 0, 0, 0}},
{2, "lstat", INT, {STRING, ADDR, 0, 0, 0, 0}},
{3, "poll", INT, {ADDR,  INT,  INT, 0, 0, 0}},
{3, "lseek", INT, {INT,  INT,  INT, 0, 0, 0}},
{6, "mmap", ADDR, {ADDR, INT, INT, INT, INT, INT}},
{3, "mprotect", INT, {ADDR,  INT,  INT, 0, 0, 0}},
{2, "munmap", INT, {ADDR,  INT, 0, 0, 0, 0}},
{1, "brk", INT, {ADDR, 0, 0, 0, 0, 0}},
{3, "rt_sigaction", INT, {INT, ADDR, ADDR, 0, 0, 0}},
{3, "rt_sigprocmask", INT, {INT, ADDR, ADDR, 0, 0, 0}},
{1, "rt_sigreturn", INT, {INT, 0, 0, 0, 0, 0}},
{3, "ioctl", INT, {INT,  INT,  VARARGS, 0, 0, 0}},
{4, "pread64", INT, {INT, ADDR, INT, INT, 0, 0}},
{4, "pwrite64", INT, {INT, ADDR, INT, INT, 0, 0}},
{3, "readv", INT, {INT, ADDR,  INT, 0, 0, 0}},
{3, "writev", INT, {INT, ADDR,  INT, 0, 0, 0}},
{2, "access", INT, {STRING,  INT, 0, 0, 0, 0}},
{1, "pipe", INT, {ARRAY, 0, 0, 0, 0, 0}},
{5, "select", INT, {INT, ADDR, ADDR, ADDR, ADDR, 0}},
{0, "sched_yield", INT, {0, 0, 0, 0, 0, 0}},
{5, "mremap", ADDR, {ADDR, INT, INT, INT, VARARGS, 0}},
{3, "msync", INT, {ADDR,  INT,  INT, 0, 0, 0}},
{3, "mincore", INT, {ADDR,  INT,  STRING, 0, 0, 0}},
{3, "madvise", INT, {ADDR,  INT,  INT, 0, 0, 0}},
{3, "shmget", INT, {INT,  INT,  INT, 0, 0, 0}},
{3, "shmat", ADDR, {INT, ADDR, INT, 0, 0, 0}},
{3, "shmctl", INT, {INT,  INT, ADDR, 0, 0, 0}},
{1, "dup", INT, {INT, 0, 0, 0, 0, 0}},
{2, "dup2", INT, {INT,  INT, 0, 0, 0, 0}},
{0, "pause", INT, {0, 0, 0, 0, 0, 0}},
{2, "nanosleep", INT, {ADDR, ADDR, 0, 0, 0, 0}},
{2, "getitimer", INT, {INT, ADDR, 0, 0, 0, 0}},
{1, "alarm", INT, {INT, 0, 0, 0, 0, 0}},
{3, "setitimer", INT, {INT, ADDR, ADDR, 0, 0, 0}},
{0, "getpid", INT, {0, 0, 0, 0, 0, 0}},
{4, "sendfile", INT, {INT,  INT, ADDR,  INT, 0, 0}},
{3, "socket", INT, {INT,  INT,  INT, 0, 0, 0}},
{3, "connect", INT, {INT, ADDR, INT, 0, 0, 0}},
{3, "accept", INT, {INT, ADDR, ADDR, 0, 0, 0}},
{6, "sendto", INT, {INT, ADDR, INT, INT, ADDR, INT}},
{6, "recvfrom", INT, {INT, ADDR, INT, INT, ADDR, ADDR}},
{3, "sendmsg", INT, {INT, ADDR,  INT, 0, 0, 0}},
{3, "recvmsg", INT, {INT, ADDR,  INT, 0, 0, 0}},
{2, "shutdown", INT, {INT,  INT, 0, 0, 0, 0}},
{3, "bind", INT, {INT, ADDR, INT, 0, 0, 0}},
{2, "listen", INT, {INT,  INT, 0, 0, 0, 0}},
{3, "getsockname", INT, {INT, ADDR, ADDR, 0, 0, 0}},
{3, "getpeername", INT, {INT, ADDR, ADDR, 0, 0, 0}},
{4, "socketpair", INT, {INT,  INT,  INT,  ARRAY, 0, 0}},
{5, "setsockopt", INT, {INT,  INT,  INT, ADDR,  INT, 0}},
{5, "getsockopt", INT, {INT,  INT,  INT, ADDR, ADDR, 0}},
{5, "clone", INT, {INT, ADDR, ADDR, ADDR, ADDR, 0}},
{0, "fork", INT, {0, 0, 0, 0, 0, 0}},
{0, "vfork", INT, {0, 0, 0, 0, 0, 0}},
{3, "execve", INT, {STRING,  ARRAY,  ARRAY, 0, 0, 0}},
{1, "exit", VOID, {INT, 0, 0, 0, 0, 0}},
{4, "wait4", INT, {INT, ADDR,  INT, ADDR, 0, 0}},
{2, "kill", INT, {INT,  INT, 0, 0, 0, 0}},
{1, "uname", INT, {ADDR, 0, 0, 0, 0, 0}},
{3, "semget", INT, {INT,  INT,  INT, 0, 0, 0}},
{3, "semop", INT, {INT, ADDR, INT, 0, 0, 0}},
{4, "semctl", INT, {INT, INT, INT, VARARGS, 0, 0}},
{1, "shmdt", INT, {ADDR, 0, 0, 0, 0, 0}},
{2, "msgget", INT, {INT,  INT, 0, 0, 0, 0}},
{4, "msgsnd", INT, {INT, ADDR,  INT,  INT, 0, 0}},
{5, "msgrcv", INT, {INT, ADDR,  INT,  INT,  INT, 0}},
{3, "msgctl", INT, {INT,  INT, ADDR, 0, 0, 0}},
{3, "fcntl", INT, {INT, INT, VARARGS, 0, 0, 0}},
{2, "flock", INT, {INT,  INT, 0, 0, 0, 0}},
{1, "fsync", INT, {INT, 0, 0, 0, 0, 0}},
{1, "fdatasync", INT, {INT, 0, 0, 0, 0, 0}},
{2, "truncate", INT, {STRING,  INT, 0, 0, 0, 0}},
{2, "ftruncate", INT, {INT,  INT, 0, 0, 0, 0}},
{3, "getdents", INT, {INT, ADDR,  INT, 0, 0, 0}},
{2, "getcwd", ADDR, {STRING,  INT, 0, 0, 0, 0}},
{1, "chdir", INT, {STRING, 0, 0, 0, 0, 0}},
{1, "fchdir", INT, {INT, 0, 0, 0, 0, 0}},
{2, "rename", INT, {STRING,  STRING, 0, 0, 0, 0}},
{2, "mkdir", INT, {STRING,  INT, 0, 0, 0, 0}},
{1, "rmdir", INT, {STRING, 0, 0, 0, 0, 0}},
{2, "creat", INT, {STRING,  INT, 0, 0, 0, 0}},
{2, "link", INT, {STRING,  STRING, 0, 0, 0, 0}},
{1, "unlink", INT, {STRING, 0, 0, 0, 0, 0}},
{2, "symlink", INT, {STRING,  STRING, 0, 0, 0, 0}},
{3, "readlink", INT, {STRING,  STRING,  INT, 0, 0, 0}},
{2, "chmod", INT, {STRING,  INT, 0, 0, 0, 0}},
{2, "fchmod", INT, {INT,  INT, 0, 0, 0, 0}},
{3, "chown", INT, {STRING,  INT,  INT, 0, 0, 0}},
{3, "fchown", INT, {INT,  INT,  INT, 0, 0, 0}},
{3, "lchown", INT, {STRING,  INT,  INT, 0, 0, 0}},
{1, "umask", INT, {INT, 0, 0, 0, 0, 0}},
{2, "gettimeofday", INT, {ADDR, ADDR, 0, 0, 0, 0}},
{2, "getrlimit", INT, {INT, ADDR, 0, 0, 0, 0}},
{2, "getrusage", INT, {INT, ADDR, 0, 0, 0, 0}},
{1, "sysinfo", INT, {ADDR, 0, 0, 0, 0, 0}},
{1, "times", INT, {ADDR, 0, 0, 0, 0, 0}},
{4, "ptrace", INT, {UNKNOWN,  INT, ADDR, ADDR, 0, 0}},
{0, "getuid", INT, {0, 0, 0, 0, 0, 0}},
{3, "syslog", INT, {INT,  STRING,  INT, 0, 0, 0}},
{0, "getgid", INT, {0, 0, 0, 0, 0, 0}},
{1, "setuid", INT, {INT, 0, 0, 0, 0, 0}},
{1, "setgid", INT, {INT, 0, 0, 0, 0, 0}},
{0, "geteuid", INT, {0, 0, 0, 0, 0, 0}},
{0, "getegid", INT, {0, 0, 0, 0, 0, 0}},
{2, "setpgid", INT, {INT,  INT, 0, 0, 0, 0}},
{0, "getppid", INT, {0, 0, 0, 0, 0, 0}},
{0, "getpgrp", INT, {0, 0, 0, 0, 0, 0}},
{0, "setsid", INT, {0, 0, 0, 0, 0, 0}},
{2, "setreuid", INT, {INT,  INT, 0, 0, 0, 0}},
{2, "setregid", INT, {INT,  INT, 0, 0, 0, 0}},
{2, "getgroups", INT, {INT,  ARRAY, 0, 0, 0, 0}},
{2, "setgroups", INT, {INT, ADDR, 0, 0, 0, 0}},
{3, "setresuid", INT, {INT,  INT,  INT, 0, 0, 0}},
{3, "getresuid", INT, {ADDR, ADDR, ADDR, 0, 0, 0}},
{3, "setresgid", INT, {INT,  INT,  INT, 0, 0, 0}},
{3, "getresgid", INT, {ADDR, ADDR, ADDR, 0, 0, 0}},
{1, "getpgid", INT, {INT, 0, 0, 0, 0, 0}},
{1, "setfsuid", INT, {INT, 0, 0, 0, 0, 0}},
{1, "setfsgid", INT, {INT, 0, 0, 0, 0, 0}},
{1, "getsid", INT, {INT, 0, 0, 0, 0, 0}},
{2, "capget", INT, {INT,  INT, 0, 0, 0, 0}},
{2, "capset", INT, {INT,  INT, 0, 0, 0, 0}},
{1, "rt_sigpending", INT, {ADDR, 0, 0, 0, 0, 0}},
{3, "rt_sigtimedwait", INT, {ADDR, ADDR, ADDR, 0, 0, 0}},
{3, "rt_sigqueueinfo", INT, {INT,  INT, ADDR, 0, 0, 0}},
{1, "rt_sigsuspend", INT, {ADDR, 0, 0, 0, 0, 0}},
{2, "sigaltstack", INT, {ADDR, ADDR, 0, 0, 0, 0}},
{2, "utime", INT, {STRING, ADDR, 0, 0, 0, 0}},
{3, "mknod", INT, {STRING,  INT,  INT, 0, 0, 0}},
{1, "uselib", INT, {STRING, 0, 0, 0, 0, 0}},
{1, "personality", INT, {INT, 0, 0, 0, 0, 0}},
{2, "ustat", INT, {INT, ADDR, 0, 0, 0, 0}},
{2, "statfs", INT, {STRING, ADDR, 0, 0, 0, 0}},
{2, "fstatfs", INT, {INT, ADDR, 0, 0, 0, 0}},
{2, "sysfs", INT, {INT,  STRING, 0, 0, 0, 0}},
{2, "getpriority", INT, {INT,  INT, 0, 0, 0, 0}},
{3, "setpriority", INT, {INT,  INT,  INT, 0, 0, 0}},
{2, "sched_setparam", INT, {INT, ADDR, 0, 0, 0, 0}},
{2, "sched_getparam", INT, {INT, ADDR, 0, 0, 0, 0}},
{3, "sched_setscheduler", INT, {INT,  INT, ADDR, 0, 0, 0}},
{1, "sched_getscheduler", INT, {INT, 0, 0, 0, 0, 0}},
{1, "sched_get_priority_max", INT, {INT, 0, 0, 0, 0, 0}},
{1, "sched_get_priority_min", INT, {INT, 0, 0, 0, 0, 0}},
{2, "sched_rr_get_interval", INT, {INT, ADDR, 0, 0, 0, 0}},
{2, "mlock", INT, {ADDR,  INT, 0, 0, 0, 0}},
{2, "munlock", INT, {ADDR,  INT, 0, 0, 0, 0}},
{1, "mlockall", INT, {INT, 0, 0, 0, 0, 0}},
{0, "munlockall", INT, {0, 0, 0, 0, 0, 0}},
{0, "vhangup", INT, {0, 0, 0, 0, 0, 0}},
{3, "modify_ldt", INT, {INT, ADDR,  INT, 0, 0, 0}},
{2, "pivot_root", INT, {STRING,  STRING, 0, 0, 0, 0}},
{1, "_sysctl", INT, {ADDR, 0, 0, 0, 0, 0}},
{5, "prctl", INT, {INT,  INT,  INT, UNKNOWN,  INT, 0}},
{2, "arch_prctl", INT, {INT,  INT, 0, 0, 0, 0}},
{1, "adjtimex", INT, {ADDR, 0, 0, 0, 0, 0}},
{2, "setrlimit", INT, {INT, ADDR, 0, 0, 0, 0}},
{1, "chroot", INT, {STRING, 0, 0, 0, 0, 0}},
{0, "sync", VOID, {0, 0, 0, 0, 0, 0}},
{1, "acct", INT, {STRING, 0, 0, 0, 0, 0}},
{2, "settimeofday", INT, {ADDR, ADDR, 0, 0, 0, 0}},
{5, "mount", INT, {STRING,  STRING, ADDR,  INT, ADDR, 0}},
{2, "umount2", INT, {STRING,  INT, 0, 0, 0, 0}},
{2, "swapon", INT, {STRING,  INT, 0, 0, 0, 0}},
{1, "swapoff", INT, {STRING, 0, 0, 0, 0, 0}},
{4, "reboot", INT, {INT,  INT,  INT, ADDR, 0, 0}},
{2, "sethostname", INT, {STRING,  INT, 0, 0, 0, 0}},
{2, "setdomainname", INT, {STRING,  INT, 0, 0, 0, 0}},
{1, "iopl", INT, {INT, 0, 0, 0, 0, 0}},
{3, "ioperm", INT, {INT,  INT,  INT, 0, 0, 0}},
{2, "create_module", STRING, {STRING,  INT, 0, 0, 0, 0}},
{3, "init_module", INT, {ADDR,  INT, STRING, 0, 0, 0}},
{2, "delete_module", INT, {STRING,  INT, 0, 0, 0, 0}},
{1, "get_kernel_syms", INT, {ADDR, 0, 0, 0, 0, 0}},
{5, "query_module", INT, {STRING,  INT, ADDR,  INT, ADDR, 0}},
{4, "quotactl", INT, {INT,  STRING,  INT,  STRING, 0, 0}},
{3, "nfsservctl", INT, {INT, ADDR, ADDR, 0, 0, 0}},
{0, "getpmsg", VOID, {0, 0, 0, 0, 0, 0}},
{0, "putpmsg", VOID, {0, 0, 0, 0, 0, 0}},
{0, "afs_syscall", VOID, {0, 0, 0, 0, 0, 0}},
{0, "tuxcall", VOID, {0, 0, 0, 0, 0, 0}},
{0, "security", VOID, {0, 0, 0, 0, 0, 0}},
{0, "gettid", INT, {0, 0, 0, 0, 0, 0}},
{3, "readahead", INT, {INT,  INT,  INT, 0, 0, 0}},
{5, "setxattr", INT, {STRING,  STRING, ADDR,  INT,  INT, 0}},
{5, "lsetxattr", INT, {STRING,  STRING, ADDR,  INT,  INT, 0}},
{5, "fsetxattr", INT, {INT,  STRING, ADDR,  INT,  INT, 0}},
{4, "getxattr", INT, {STRING,  STRING, ADDR,  INT, 0, 0}},
{4, "lgetxattr", INT, {STRING,  STRING, ADDR,  INT, 0, 0}},
{4, "fgetxattr", INT, {INT,  STRING, ADDR,  INT, 0, 0}},
{3, "listxattr", INT, {STRING,  STRING,  INT, 0, 0, 0}},
{3, "llistxattr", INT, {STRING,  STRING,  INT, 0, 0, 0}},
{3, "flistxattr", INT, {INT,  STRING,  INT, 0, 0, 0}},
{2, "removexattr", INT, {STRING,  STRING, 0, 0, 0, 0}},
{2, "lremovexattr", INT, {STRING,  STRING, 0, 0, 0, 0}},
{2, "fremovexattr", INT, {INT,  STRING, 0, 0, 0, 0}},
{2, "tkill", INT, {INT,  INT, 0, 0, 0, 0}},
{1, "time", INT, {ADDR, 0, 0, 0, 0, 0}},
{6, "futex", INT, {ADDR,  INT,  INT, ADDR, ADDR,  INT}},
{3, "sched_setaffinity", INT, {INT,  INT, ADDR, 0, 0, 0}},
{3, "sched_getaffinity", INT, {INT,  INT, ADDR, 0, 0, 0}},
{1, "set_thread_area", INT, {ADDR, 0, 0, 0, 0, 0}},
{2, "io_setup", INT, {INT, ADDR, 0, 0, 0, 0}},
{1, "io_destroy", INT, {INT, 0, 0, 0, 0, 0}},
{5, "io_getevents", INT, {INT,  INT,  INT, ADDR, ADDR, 0}},
{3, "io_submit", INT, {INT,  INT, ADDR, 0, 0, 0}},
{3, "io_cancel", INT, {INT, ADDR, ADDR, 0, 0, 0}},
{1, "get_thread_area", INT, {ADDR, 0, 0, 0, 0, 0}},
{3, "lookup_dcookie", INT, {INT,  STRING,  INT, 0, 0, 0}},
{1, "epoll_create", INT, {INT, 0, 0, 0, 0, 0}},
{0, "epoll_ctl_old", VOID, {0, 0, 0, 0, 0, 0}},
{0, "epoll_wait_old", VOID, {0, 0, 0, 0, 0, 0}},
{5, "remap_file_pages", INT, {ADDR,  INT,  INT,  INT,  INT, 0}},
{3, "getdents64", INT, {INT, ADDR, INT, 0, 0, 0}},
{1, "set_tid_address", INT, {ADDR, 0, 0, 0, 0, 0}},
{0, "restart_syscall", VOID, {0, 0, 0, 0, 0, 0}},
{4, "semtimedop", INT, {INT, ADDR, INT, ADDR, 0, 0}},
{4, "fadvise64", INT, {INT, INT, INT, INT, 0, 0}},
{3, "timer_create", INT, {INT, ADDR, ADDR, 0, 0, 0}},
{4, "timer_settime", INT, {ADDR,  INT, ADDR, ADDR, 0, 0}},
{2, "timer_gettime", INT, {ADDR, ADDR, 0, 0, 0, 0}},
{1, "timer_getoverrun", INT, {ADDR, 0, 0, 0, 0, 0}},
{1, "timer_delete", INT, {ADDR, 0, 0, 0, 0, 0}},
{2, "clock_settime", INT, {INT, ADDR, 0, 0, 0, 0}},
{2, "clock_gettime", INT, {INT, ADDR, 0, 0, 0, 0}},
{2, "clock_getres", INT, {INT, ADDR, 0, 0, 0, 0}},
{4, "clock_nanosleep", INT, {INT,  INT, ADDR, ADDR, 0, 0}},
{1, "exit_group", VOID, {INT, 0, 0, 0, 0, 0}},
{4, "epoll_wait", INT, {INT, ADDR,  INT,  INT, 0, 0}},
{4, "epoll_ctl", INT, {INT,  INT,  INT, ADDR, 0, 0}},
{3, "tgkill", INT, {INT,  INT,  INT, 0, 0, 0}},
{2, "utimes", INT, {STRING,  ARRAY, 0, 0, 0, 0}},
{0, "vserver", VOID, {0, 0, 0, 0, 0, 0}},
{6, "mbind", INT, {ADDR,  INT,  INT, ADDR,  INT, INT}},
{3, "set_mempolicy", INT, {INT, ADDR, INT, 0, 0, 0}},
{5, "get_mempolicy", INT, {ADDR, ADDR, INT,  INT, UNKNOWN, 0}},
{2, "mq_open", INT, {STRING,  INT, 0, 0, 0, 0}},
{1, "mq_unlink", INT, {STRING, 0, 0, 0, 0, 0}},
{5, "mq_timedsend", INT, {INT,  STRING, INT, INT, ADDR, 0}},
{5, "mq_timedreceive", INT, {INT,  STRING,  INT, ADDR, ADDR, 0}},
{2, "mq_notify", INT, {INT, ADDR, 0, 0, 0, 0}},
{3, "mq_getsetattr", INT, {INT, ADDR, ADDR, 0, 0, 0}},
{4, "kexec_load", INT, {INT,  INT, ADDR,  INT, 0, 0}},
{4, "waitid", INT, {INT,  INT, ADDR,  INT, 0, 0}},
{5, "add_key", UNKNOWN, {STRING,  STRING, ADDR,  INT,  UNKNOWN, 0}},
{4, "request_key", UNKNOWN, {STRING,  STRING,  STRING,  UNKNOWN, 0, 0}},
{2, "keyctl", INT, {INT, VARARGS, 0, 0, 0, 0}},
{3, "ioprio_set", INT, {INT,  INT,  INT, 0, 0, 0}},
{2, "ioprio_get", INT, {INT,  INT, 0, 0, 0, 0}},
{0, "inotify_init", INT, {0, 0, 0, 0, 0, 0}},
{3, "inotify_add_watch", INT, {INT,  STRING,  INT, 0, 0, 0}},
{2, "inotify_rm_watch", INT, {INT,  INT, 0, 0, 0, 0}},
{4, "migrate_pages", INT, {INT,  INT, ADDR, ADDR, 0, 0}},
{3, "openat", INT, {INT,  STRING,  INT, 0, 0, 0}},
{3, "mkdirat", INT, {INT,  STRING,  INT, 0, 0, 0}},
{4, "mknodat", INT, {INT,  STRING,  INT,  INT, 0, 0}},
{5, "fchownat", INT, {INT,  STRING,  INT,  INT,  INT, 0}},
{3, "futimesat", INT, {INT,  STRING, ARRAY, 0, 0, 0}},
{0, "newfstatat", VOID, {0, 0, 0, 0, 0, 0}},
{3, "unlinkat", INT, {INT,  STRING,  INT, 0, 0, 0}},
{4, "renameat", INT, {INT,  STRING,  INT,  STRING, 0, 0}},
{5, "linkat", INT, {INT,  STRING,  INT,  STRING,  INT, 0}},
{3, "symlinkat", INT, {STRING,  INT,  STRING, 0, 0, 0}},
{4, "readlinkat", INT, {INT,  STRING,  STRING,  INT, 0, 0}},
{4, "fchmodat", INT, {INT,  STRING,  INT,  INT, 0, 0}},
{4, "faccessat", INT, {INT,  STRING,  INT,  INT, 0, 0}},
{6, "pselect6", INT, {INT, ADDR, ADDR, ADDR, ADDR, ADDR}},
{4, "ppoll", INT, {ADDR,  INT, ADDR, ADDR, 0, 0}},
{1, "unshare", INT, {INT, 0, 0, 0, 0, 0}},
{2, "set_robust_list", INT, {ADDR,  INT, 0, 0, 0, 0}},
{3, "get_robust_list", INT, {INT, ADDR, ADDR, 0, 0, 0}},
{6, "splice", INT, {INT, ADDR,  INT, ADDR,  INT,  INT}},
{4, "tee", INT, {INT,  INT,  INT,  INT, 0, 0}},
{4, "sync_file_range", INT, {INT,  INT,  INT, INT, 0, 0}},
{4, "vmsplice", INT, {INT, ADDR,  INT,  INT, 0, 0}},
{6, "move_pages", INT, {INT,  INT, ADDR, ADDR, ADDR,  INT}},
{4, "utimensat", INT, {INT,  STRING, ARRAY,  INT, 0, 0}},
{5, "epoll_pwait", INT, {INT, ADDR,  INT,  INT, ADDR, 0}},
{3, "signalfd", INT, {INT, ADDR,  INT, 0, 0, 0}},
{2, "timerfd_create", INT, {INT,  INT, 0, 0, 0, 0}},
{2, "eventfd", INT, {INT,  INT, 0, 0, 0, 0}},
{4, "fallocate", INT, {INT,  INT,  INT,  INT, 0, 0}},
{4, "timerfd_settime", INT, {INT,  INT, ADDR, ADDR, 0, 0}},
{2, "timerfd_gettime", INT, {INT, ADDR, 0, 0, 0, 0}},
{4, "accept4", INT, {INT, ADDR, ADDR,  INT, 0, 0}},
{3, "signalfd4", INT, {INT, ADDR, ADDR, 0, 0, 0}},
{1, "eventfd2", INT, {INT, INT, 0, 0, 0, 0}},
{1, "epoll_create1", INT, {INT, 0, 0, 0, 0, 0}},
{3, "dup3", INT, {INT,  INT,  INT, 0, 0, 0}},
{2, "pipe2", INT, {ARRAY,  INT, 0, 0, 0, 0}},
{1, "inotify_init1", INT, {INT, 0, 0, 0, 0, 0}},
{4, "preadv", INT, {INT, ADDR,  INT,  INT, 0, 0}},
{4, "pwritev", INT, {INT, ADDR,  INT, INT, 0, 0}},
{4, "rt_tgsigqueueinfo", INT, {INT,  INT,  INT, ADDR, 0, 0}},
{5, "perf_event_open", INT, {ADDR, INT,  INT,  INT, INT, 0}},
{5, "recvmmsg", INT, {INT, ADDR,  INT,  INT, ADDR, 0}},
{0, "fanotify_init", VOID, {0, 0, 0, 0, 0, 0}},
{0, "fanotify_mark", VOID, {0, 0, 0, 0, 0, 0}},
{0, "prlimit64", VOID, {0, 0, 0, 0, 0, 0}},
{0, "name_to_handle_at", VOID, {0, 0, 0, 0, 0, 0}},
{0, "open_by_handle_at", VOID, {0, 0, 0, 0, 0, 0}},
{0, "clock_adjtime", VOID, {0, 0, 0, 0, 0, 0}},
{1, "syncfs", INT, {INT, 0, 0, 0, 0, 0}},
{4, "sendmmsg", INT, {INT, ADDR,  INT,  INT, 0, 0}},
{2, "setns", INT, {INT,  INT, 0, 0, 0, 0}},
{3, "getcpu", INT, {ADDR, ADDR, ADDR, 0, 0, 0}},
{6, "process_vm_readv", INT, {INT, ADDR,  INT, ADDR,  INT,  INT}},
{6, "process_vm_writev", INT, {INT, ADDR, INT, ADDR, INT, UNKNOWN}},
{5, "kcmp", INT, {INT,  INT,  INT,  INT,  INT, 0}},
{3, "finit_module", INT, {INT,  STRING,  INT, 0, 0, 0}},
#endif
