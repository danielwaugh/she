from django.conf.urls import url

from . import views

urlpatterns = [
	url(r'^$', views.index, name='index'),
	url(r'hubconnection1/', views.hubconnection1, name='hubconnection1'),
	url(r'hubconnection2/', views.hubconnection2, name='hubconnection2'),
	url(r'hubconnection3/', views.hubconnection3, name='hubconnection3'),
	url(r'hubconnection4/', views.hubconnection4, name='hubconnection4'),
	url(r'smartplugconnection/', views.smartplugconnection, name='smartplugconnection'),
	]