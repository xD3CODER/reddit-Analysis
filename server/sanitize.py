#!/usr/bin/python
from __future__ import print_function
import sys
import os
import bz2
import ujson

# Parameters
OUT_FILE_PREFIX = 'out/'
OUT_FILE_SUFFIX = '.json'
PROGRESS = False
DEBUG = False
DEBUG_LIMIT = 2000
VERBOSE = False

# Debug flag
for arg in sys.argv[1:]:
    if arg == "-d" or arg == '--debug':
        DEBUG = True
        sys.argv.remove(arg)

    if arg == "-p" or arg == '--progress':
        PROGRESS = True
        sys.argv.remove(arg)

    if arg == "-v" or arg == '--verbose':
        VERBOSE = True
        sys.argv.remove(arg)


# Check if there is at least one file to process
if len(sys.argv) <= 1:
    print("Usage : %s raw_data_file.bz2" % (sys.argv[0]))
    sys.exit(1)

filenames = sys.argv[1:]

# Process files
for filename in filenames:
    print("\nDoing %s" % (filename))

    # Open Input File
    try:
        handle = bz2.BZ2File(filename)
    except IOError as e:
        print("> ERROR : Unable to open file %s (msg : %s)" % (filename, e.strerror))
        continue

    # Open Output File
    filename_clean = os.path.basename(filename)
    filename_clean = os.path.splitext(filename_clean)[0]
    filename_clean = OUT_FILE_PREFIX + filename_clean + OUT_FILE_SUFFIX
    try:
        out_handle = open(filename_clean, 'w')
    except IOError as e:
        print("> ERROR : Unable to open out file %s (msg : %s)" % (filename_clean, e.strerror))
        continue
    out_handle.write("{\"messages\": [\n")

    # Iterate over each line to do the job
    i = 0

    if PROGRESS:
        # Calculate file size
        print ("> Calculating progress data ...")
        handle.seek(0, os.SEEK_END)
        raw_size = handle.tell()
        handle.seek(0)

    print ("> Converting datas ...")

    for line in handle:
        obj = ujson.loads(line)

        if VERBOSE:
            if PROGRESS:
                progressPercent = (float(handle.tell()) / float(raw_size)) * 100
                print (">> %s - %s - %.2f%%" % (obj['link_id'], str(i), progressPercent), end="\r")
            else:
                print (">> %s - %s" % (obj['link_id'], str(i)))
        else:
            if i % 2000 == 0:
                sys.stdout.write("\r Done %d" % i)
                sys.stdout.flush()

        # Delete datas
        obj.pop('retrieved_on', None)
        obj.pop('score_hidden', None)
        obj.pop('score', None)
        obj.pop('subreddit_id', None)
        obj.pop('archived', None)
        obj.pop('distinguished', None)
        obj.pop('gilded', None)
        obj.pop('author_flair_css_class', None)
        obj.pop('author_flair_text', None)
        obj.pop('controversiality', None)
        obj.pop('body', None)
        obj.pop('id', None)

        # Write data to out file
        out_handle.write(ujson.dumps(obj) + ",\n")

        # Debug Mode
        if DEBUG:
            if i >= DEBUG_LIMIT:
                print("- [DEBUG] Hit debug limit for this file.")
                break

        i += 1

    # Clear out handle
    out_handle.seek(-2, os.SEEK_END)
    out_handle.truncate()
    out_handle.write("\n]}\n")
    out_handle.close()

print("\nRaw datas sanitized with success with %d messages." % i)
