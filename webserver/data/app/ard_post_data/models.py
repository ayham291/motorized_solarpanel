from django.db import models


class Ini_Sensor(models.Model):
    sensor = models.CharField(max_length=50, null=True)
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f'{self.sensor}'

class Offset(models.Model):
    offset = models.DecimalField(max_digits=10, decimal_places=0, null=True)
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f'{self.offset}'

class Kompass(models.Model):
    sensor = models.DecimalField(max_digits=10, decimal_places=0, null=True)
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f'{self.sensor}'

class LDRUP(models.Model):
    sensor = models.IntegerField(null=True)
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f'{self.sensor}'

class LDRLAY(models.Model):
    sensor = models.IntegerField(null=True)
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f'{self.sensor}'

class Temp(models.Model):
    sensor = models.DecimalField(max_digits=10, decimal_places=2, null=True)
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f'{self.sensor}'

class Tilt(models.Model):
    motor = models.CharField(max_length=50, null=True)
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f'{self.motor}'

class Turn(models.Model):
    motor = models.CharField(max_length=50, null=True)
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f'{self.motor}'

class GenStatus(models.Model):
    status = models.IntegerField(null=True)
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f'{self.status}'
class SunPos(models.Model):
    pos = models.IntegerField(null=True)
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f'{self.pos}'
