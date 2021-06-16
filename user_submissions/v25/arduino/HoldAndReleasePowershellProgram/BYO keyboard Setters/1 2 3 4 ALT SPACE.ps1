#explain what this is setting the keys to
Write-Host "1		2		3"
Write-Host "4		ALT		SPACE"
#create the serial port object
$port = New-Object System.IO.Ports.SerialPort

#loop through the serial ports looking for one with a Device Description of "ItsyBitsy M0 Express"
$portList = get-pnpdevice -class Ports -ea 0
if ($portList) {
     foreach($device in $portList) {
          if ($device.Present) {
               #Write-Host $device.DeviceID
			   $deviceDesc = Get-PnpDevice -InstanceId $device.DeviceID | Get-PnpDeviceProperty -KeyName 'DEVPKEY_Device_BusReportedDeviceDesc' 
			   #Write-Host $deviceDesc.Data
			   if($deviceDesc.Data -eq "ItsyBitsy M0 Express")
			   {
				Write-Host "Found BYO-Keyboard"
				$deviceName = Get-PnpDevice -InstanceId $device.DeviceID | Get-PnpDeviceProperty -KeyName 'DEVPKEY_Device_FriendlyName'
				$portName = $deviceName.Data.Split("(")[1].Split(")")[0]
				#Write-Host $portName
				$port.PortName = $deviceName.Data.Split("(")[1].Split(")")[0]
			   }
          }
     }
}


$port.BaudRate = "9600"
$port.Parity = "None"
$port.DataBits = 8
$port.StopBits = 1
$port.ReadTimeout = 9000 # 9 seconds
$port.DtrEnable = "true"

$port.open() #opens serial connection

Start-Sleep 2 # wait 2 seconds until Arduino is ready

$port.Write("49,50,51,52,130,32") #writes your content to the serial connection

$port.close()