from django.db import models


# Create your models here.

class Product(models.Model):
    sku = models.CharField(max_length=8, verbose_name='SKU')
    name = models.CharField(max_length=255)
