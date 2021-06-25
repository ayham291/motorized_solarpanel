from django.contrib import admin
from .models import *

class Views(admin.ModelAdmin):
    list_display = ('sensor', 'timestamp')


admin.site.register(Ini_Sensor, Views)
admin.site.register(Kompass, Views)
admin.site.register(LDRUP, Views)
admin.site.register(LDRLAY, Views)
admin.site.register(Temp, Views)
admin.site.register(Tilt)
admin.site.register(Turn)
admin.site.register(GenStatus)
