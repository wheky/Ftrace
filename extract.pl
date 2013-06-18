#!/usr/bin/perl

use strict;
use warnings;

sub replace
{
    my $pattern = "([ ,\(])". $_[1] ."(?: )+[A-Za-z_][A-Za-z_0-9]*([,\)])";

    #print $pattern, "\n";
    $_[0] =~ s/$pattern/$1$_[2]$2/g;
    $_[0] =~ s/^$_[1] /$_[2] /g;
    return $_[0];
}

sub replace_int
{
    &replace($_[0], $_[1], "INT");
}

sub replace_string
{
    &replace($_[0], $_[1], "STRING");
}

sub display_syscall
{
    my $name = $_[0];
    $_ = $_[1];
    my $count = () = $_ =~ /([\(, ])[A-Z]+/g;

    my $ret = $_;

    my @ret = split(/ /, $_);
    print "{$count, \"$name\", $ret[0], {";

    @ret = split(/\(/, $_);

    $_ = $ret[1];

    @ret = split(/\)/, $_);
    $_ = $ret[0];
    @ret = split(/,/, $_);
    my $i;
    for ($i = 0; $i < $count; ++$i) {
	unless ($i == 0) { print ", "; }
	print $ret[$i];
    }
    for (; $i < 6; ++$i) {
	unless ($i == 0) { print ", "; }
	print "0";
    }
    print "}},", "\n";
}

sub main
{
    open(my $fh, "/usr/include/asm/unistd_64.h");
    print "#ifndef GENERATED_H_", "\n";
    print "#define GENERATED_H_", "\n";
    print "\n";

    while (my $line = <$fh>) {
	if ($line =~ /^#define __NR_([a-z_0-9]+)(?:[ \t])+[0-9]{1,3}$/) {
	    my $string = "man 2 $1 | tr \"\\n\" \" \" | sed 's/  / /g' | grep -o '[a-z_]* [*]*$1(\\(\\]\\|[a-zA-Z0-9,*\\t _\\[]\\)*);' | sed 's/  / /g' | head -1";
	    my $syscall = $1;

	    $_ = `$string`;
	    $_ =~ s/^\s+//;
	    chomp;
	    unless ($_ eq "") {
		$_ =~ s/\/\*.*\*\///g;

		$_ =~ s/const //g;
		$_ =~ s/unsigned //g;

		$_ =~ s/\.\.\.(?: )*\)/VARARGS)/;

		$_ =~ s/[A-Za-z_][A-Za-z0-9_ *]+\[[A-Za-z0-9]*\]([,\)])/ARRAY$1/g;
		# TODO for the return type
		$_ = &replace_int($_, "mqd_t");

		$_ = &replace_int($_, "key_t");
		$_ = &replace_int($_, "size_t");
		$_ = &replace_int($_, "ssize_t");
		$_ = &replace_int($_, "socklen_t");
		$_ = &replace_int($_, "int");
		$_ = &replace_int($_, "off_t");
		$_ = &replace_int($_, "nfds_t");
		$_ = &replace_int($_, "pid_t");
		$_ = &replace_int($_, "uid_t");
		$_ = &replace_int($_, "gid_t");
		$_ = &replace_int($_, "time_t");
		$_ = &replace_int($_, "long");
		$_ = &replace_int($_, "dev_t");
		$_ = &replace_int($_, "mode_t");
		$_ = &replace_int($_, "uint32_t");
		$_ = &replace_int($_, "cap_user_header_t");
		$_ = &replace_int($_, "off64_t");
		$_ = &replace_int($_, "cap_user_data_t");
		$_ = &replace_int($_, "clock_t");
		$_ = &replace_int($_, "aio_context_t");
		$_ = &replace_int($_, "u64");
		$_ = &replace_int($_, "clockid_t");
		$_ = &replace_int($_, "id_t");
		$_ = &replace_int($_, "id_type_t");
		$_ = &replace_int($_, "idtype_t");

		# do the strings before addr
		$_ =~ s/([ \(,])char(?: )*\*(?: )*[a-z0-9_A-Z]+([\),])/$1STRING$2/g;
		$_ = &replace_string($_, "caddr_t");

		$_ =~ s/[a-z0-9_ A-Z*]*\*[a-z0-9_ A-Z*]+([,\)])/ADDR$1/g;
		$_ =~ s/^[a-z0-9_]+ \*([a-z0-9_ *]+)\(/ADDR $1\(/;
		$_  =~ s/timer_t [A-Za-z_][A-Za-z_0-9]*([,\)])/ADDR$1/g;
		$_  =~ s/timer_t /ADDR /g;
		# TODO test the above with mmap e.g

		$_ =~ s/^void(?: )+/VOID /;
		$_ =~ s/\((?: )*void(?: )*\)/\(\)/;

		# because we can have something like "unsigned name"...

		$_ =~ s/([\(,])(?: )*[a-z_][a-z_0-9]*(?: )*([\),])/$1INT$2/g;

		# at last, make the other UNKNOWN

		$_ =~ s/(?:[a-z0-9_]+(?: )*)+([,\)])/UNKNOWN$1/g;
		$_ =~ s/^[a-z0-9_ ]+ /UNKNOWN /;

		&display_syscall($syscall, $_);
	    } else {
		print("{0, \"$syscall\", VOID, {0, 0, 0, 0, 0, 0}},", "\n");
	    }
	}
    }
    print "\n", "#endif", "\n";
    close($fh);
}

&main;
