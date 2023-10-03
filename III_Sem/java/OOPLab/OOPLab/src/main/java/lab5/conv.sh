#!/bin/bash


for f in *.java
do
	java2html "$f"
	pandoc $(basename $f .java).java.html -o"$(basename $f .java).pdf"
done
