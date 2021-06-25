from django.shortcuts import render
from django.http import HttpResponse
from django.views.decorators.csrf import csrf_exempt
from django.views.generic import ListView
from .models import *

@csrf_exempt
def dataView(request):
    if request.method == "POST":

        kompass = request.POST.get("kompass")
        offset = request.POST.get("offset")
        ini_sensor = request.POST.get("endpost")
        temp = request.POST.get("temp")
        status = request.POST.get("status")
        tiltPanel = request.POST.get("tiltPanel")
        turnTable = request.POST.get("turnTable")
        sunpos = request.POST.get('sunpos')
        ldrup = request.POST.get('ldrup')
        ldrlay = request.POST.get('ldrlay')

        Kompass.objects.create(sensor=kompass)
        Offset.objects.create(offset=offset)
        Temp.objects.create(sensor=temp)
        Ini_Sensor.objects.create(sensor=ini_sensor)
        GenStatus.objects.create(status=status)
        Tilt.objects.create(motor=tiltPanel)
        Turn.objects.create(motor=turnTable)
        SunPos.objects.create(pos=sunpos)
        LDRUP.objects.create(sensor=ldrup)
        LDRLAY.objects.create(sensor=ldrlay)

    kompass_last = Kompass.objects.last()
    ini_sensor_last = Ini_Sensor.objects.last()
    temp_last = Temp.objects.last()
    offset_last = Offset.objects.last()
    status_last = GenStatus.objects.last()
    tiltPanel_last = Tilt.objects.last()
    turnTable_last = Turn.objects.last()
    sunpos = SunPos.objects.last()
    ldrup_last = LDRUP.objects.last()
    ldrlay_last = LDRLAY.objects.last()

    context = {'kompass': kompass_last,
                'endposition': ini_sensor_last,
                'temp': temp_last,
                'offset': offset_last,
                'status': status_last,
                'tiltPanel': tiltPanel_last,
                'turnTable': turnTable_last,
                'ldrup': ldrup_last,
                'ldrlay': ldrlay_last,
                'sunpos': sunpos,}
    print(request.POST)
    return render(request, 'ard_post_data/home.html', context)
