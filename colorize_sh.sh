#!/bin/sh


	 sed "s|A|$(echo "\033[0;31mA\033[0m")|g" \
	| sed "s|B|$(echo "\033[0;32mB\033[0m")|g" \
	| sed "s|C|$(echo "\033[0;33mC\033[0m")|g" \
	| sed "s|D|$(echo "\033[0;34mD\033[0m")|g" \
	| sed "s|E|$(echo "\033[0;35mE\033[0m")|g" \
	| sed "s|F|$(echo "\033[0;36mF\033[0m")|g" \
	| sed "s|G|$(echo "\033[1;31mG\033[0m")|g" \
	| sed "s|H|$(echo "\033[1;32mH\033[0m")|g" \
	| sed "s|I|$(echo "\033[1;33mI\033[0m")|g" \
	| sed "s|J|$(echo "\033[1;34mJ\033[0m")|g" \
	| sed "s|K|$(echo "\033[1;35mK\033[0m")|g" \
	| sed "s|L|$(echo "\033[1;36mL\033[0m")|g" \
	| sed "s|M|$(echo "\033[0;91mM\033[0m")|g" \
	| sed "s|N|$(echo "\033[0;32mN\033[0m")|g" \
	| sed "s|O|$(echo "\033[0;93mO\033[0m")|g" \
	| sed "s|P|$(echo "\033[0;94mP\033[0m")|g" \
	| sed "s|Q|$(echo "\033[0;95mQ\033[0m")|g" \
	| sed "s|R|$(echo "\033[0;96mR\033[0m")|g" \
	| sed "s|S|$(echo "\033[1;91mS\033[0m")|g" \
	| sed "s|T|$(echo "\033[1;92mT\033[0m")|g" \
	| sed "s|U|$(echo "\033[1;93mU\033[0m")|g" \
	| sed "s|V|$(echo "\033[1;94mV\033[0m")|g" \
	| sed "s|W|$(echo "\033[1;95mW\033[0m")|g" \
	| sed "s|X|$(echo "\033[1;96mX\033[0m")|g" \
	| sed "s|Y|$(echo "\033[1;37mY\033[0m")|g" \
	| sed "s|Z|$(echo "\033[0;37mZ\033[0m")|g" 