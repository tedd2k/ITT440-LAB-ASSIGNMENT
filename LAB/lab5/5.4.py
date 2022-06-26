from netmiko import ConnectHandler

myserver = {
    'device_type': 'linux',
    'host':   '192.168.90.6',  #Your Server IP
    'username': 'ted', #your Server Username
    'password': '1', #your server password
    'port' : 22,
    'secret': '',
}

net_connect = ConnectHandler(**myserver)
output = net_connect.send_command('uname -a')
print(output)
