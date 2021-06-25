#!/bin/sh

set -e

python manage.py collectstatic --noinput

uwsgi --socket :8000 --master --enable-thread --module arduino.wsgi --touch-reload=/app/reload.re
