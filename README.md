# unitree_a1_ros2
The UNOFFICIAL ROS2 driver for Unitree robotics dog A1

## Unitree A1 high level control status
Unitree A1 high level control state support statistics:  
<table class="MsoTableGrid" border="1" cellspacing="0" cellpadding="0" width="643" style="width:17.0cm;margin-left:-.25pt;border-collapse:collapse;border:none;
 mso-border-alt:solid windowtext .5pt;mso-yfti-tbllook:1184;mso-padding-alt:
 0cm 5.4pt 0cm 5.4pt">
 <tbody><tr style="mso-yfti-irow:0;mso-yfti-firstrow:yes">
  <td width="123" valign="top" style="width:92.15pt;border:solid windowtext 1.0pt;
  mso-border-alt:solid windowtext .5pt;background:#A6A6A6;mso-background-themecolor:
  background1;mso-background-themeshade:166;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span class="SpellE"><b><span lang="EN-US">H<span style="color:black;mso-color-alt:windowtext">ighState</span></span></b></span><b><span lang="EN-US"><o:p></o:p></span></b></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border:solid windowtext 1.0pt;
  border-left:none;mso-border-left-alt:solid windowtext .5pt;mso-border-alt:
  solid windowtext .5pt;background:#A6A6A6;mso-background-themecolor:background1;
  mso-background-themeshade:166;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><b><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Explanation</span><span lang="EN-US"><o:p></o:p></span></b></p>
  </td>
  <td width="170" valign="top" style="width:127.55pt;border:solid windowtext 1.0pt;
  border-left:none;mso-border-left-alt:solid windowtext .5pt;mso-border-alt:
  solid windowtext .5pt;background:#A6A6A6;mso-background-themecolor:background1;
  mso-background-themeshade:166;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><b><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Support or not</span><span lang="EN-US"><o:p></o:p></span></b></p>
  </td>
 </tr>
 <tr style="mso-yfti-irow:1">
  <td width="123" style="width:92.15pt;border:solid windowtext 1.0pt;border-top:
  none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span class="SpellE"><span lang="EN-US">levelFlag</span></span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal"><span lang="EN-US">High level or low level flag: “0x00<span class="GramE">”:high</span> level “0xff”: low level<o:p></o:p></span></p>
  </td>
  <td width="170" style="width:127.55pt;border-top:none;border-left:none;
  border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center;text-indent:5.25pt;
  mso-char-indent-count:.5"><span lang="EN-US">Support<o:p></o:p></span></p>
  </td>
 </tr>
 <tr style="mso-yfti-irow:2;height:17.0pt">
  <td width="123" valign="top" style="width:92.15pt;border:solid windowtext 1.0pt;
  border-top:none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  background:#D9E2F3;mso-background-themecolor:accent1;mso-background-themetint:
  51;padding:0cm 5.4pt 0cm 5.4pt;height:17.0pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">mode</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;background:#D9E2F3;mso-background-themecolor:
  accent1;mso-background-themetint:51;padding:0cm 5.4pt 0cm 5.4pt;height:17.0pt">
  <p class="MsoNormal"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Robot
  currently mode, “1<span class="GramE">”:stand</span> mode, “2”:walk mode</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="170" valign="top" style="width:127.55pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;background:#D9E2F3;mso-background-themecolor:
  accent1;mso-background-themetint:51;padding:0cm 5.4pt 0cm 5.4pt;height:17.0pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Not support</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
 </tr>
 <tr style="mso-yfti-irow:3">
  <td width="123" style="width:92.15pt;border:solid windowtext 1.0pt;border-top:
  none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span class="SpellE"><span lang="EN-US">imu</span></span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal"><span lang="EN-US">Quaternion </span>、<span lang="EN-US">gyroscope</span>、<span lang="EN-US">accelerometer</span>、<span lang="EN-US">temperature<o:p></o:p></span></p>
  </td>
  <td width="170" valign="top" style="width:127.55pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US">Not
  <span class="GramE">support(</span>Getting temperature in sport mode is not
  supported)<o:p></o:p></span></p>
  </td>
 </tr>
 <tr style="mso-yfti-irow:4">
  <td width="123" valign="top" style="width:92.15pt;border:solid windowtext 1.0pt;
  border-top:none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  background:#D9E2F3;mso-background-themecolor:accent1;mso-background-themetint:
  51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span class="SpellE"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">forwardSpeed</span></span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;background:#D9E2F3;mso-background-themecolor:
  accent1;mso-background-themetint:51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Walk
  forward speed</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="170" valign="top" style="width:127.55pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;background:#D9E2F3;mso-background-themecolor:
  accent1;mso-background-themetint:51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Support</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
 </tr>
 <tr style="mso-yfti-irow:5">
  <td width="123" valign="top" style="width:92.15pt;border:solid windowtext 1.0pt;
  border-top:none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span class="SpellE"><span lang="EN-US">sideSpeed</span></span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal"><span lang="EN-US">The speed of lateral walk<o:p></o:p></span></p>
  </td>
  <td width="170" valign="top" style="width:127.55pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US">Support<o:p></o:p></span></p>
  </td>
 </tr>
 <tr style="mso-yfti-irow:6">
  <td width="123" valign="top" style="width:92.15pt;border:solid windowtext 1.0pt;
  border-top:none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  background:#D9E2F3;mso-background-themecolor:accent1;mso-background-themetint:
  51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span class="SpellE"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">rotateSpeed</span></span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;background:#D9E2F3;mso-background-themecolor:
  accent1;mso-background-themetint:51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Rotation
  speed</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="170" valign="top" style="width:127.55pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;background:#D9E2F3;mso-background-themecolor:
  accent1;mso-background-themetint:51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Support</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
 </tr>
 <tr style="mso-yfti-irow:7">
  <td width="123" valign="top" style="width:92.15pt;border:solid windowtext 1.0pt;
  border-top:none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span class="SpellE"><span lang="EN-US">bodyHeight</span></span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal"><span lang="EN-US">Current body height<o:p></o:p></span></p>
  </td>
  <td width="170" valign="top" style="width:127.55pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US">Support<o:p></o:p></span></p>
  </td>
 </tr>
 <tr style="mso-yfti-irow:8">
  <td width="123" valign="top" style="width:92.15pt;border:solid windowtext 1.0pt;
  border-top:none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  background:#D9E2F3;mso-background-themecolor:accent1;mso-background-themetint:
  51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span class="SpellE"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">updownSpeed</span></span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;background:#D9E2F3;mso-background-themecolor:
  accent1;mso-background-themetint:51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Standing
  or squatting speed</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="170" valign="top" style="width:127.55pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;background:#D9E2F3;mso-background-themecolor:
  accent1;mso-background-themetint:51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Support</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
 </tr>
 <tr style="mso-yfti-irow:9">
  <td width="123" valign="top" style="width:92.15pt;border:solid windowtext 1.0pt;
  border-top:none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span class="SpellE"><span lang="EN-US">forwardPosition</span></span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal"><span lang="EN-US">Target position in front of your body<o:p></o:p></span></p>
  </td>
  <td width="170" valign="top" style="width:127.55pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US">Support<o:p></o:p></span></p>
  </td>
 </tr>
 <tr style="mso-yfti-irow:10">
  <td width="123" valign="top" style="width:92.15pt;border:solid windowtext 1.0pt;
  border-top:none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  background:#D9E2F3;mso-background-themecolor:accent1;mso-background-themetint:
  51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span class="SpellE"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">sidePosition</span></span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;background:#D9E2F3;mso-background-themecolor:
  accent1;mso-background-themetint:51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Target
  position in side of your body</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="170" valign="top" style="width:127.55pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;background:#D9E2F3;mso-background-themecolor:
  accent1;mso-background-themetint:51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Support</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
 </tr>
 <tr style="mso-yfti-irow:11">
  <td width="123" valign="top" style="width:92.15pt;border:solid windowtext 1.0pt;
  border-top:none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US">footPosition2Body<o:p></o:p></span></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal"><span lang="EN-US">Position of the feet relative to the body<o:p></o:p></span></p>
  </td>
  <td width="170" valign="top" style="width:127.55pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US">Support<o:p></o:p></span></p>
  </td>
 </tr>
 <tr style="mso-yfti-irow:12">
  <td width="123" valign="top" style="width:92.15pt;border:solid windowtext 1.0pt;
  border-top:none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  background:#D9E2F3;mso-background-themecolor:accent1;mso-background-themetint:
  51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">footSpeed2Body</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;background:#D9E2F3;mso-background-themecolor:
  accent1;mso-background-themetint:51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Foot
  speed relative to the body</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="170" valign="top" style="width:127.55pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;background:#D9E2F3;mso-background-themecolor:
  accent1;mso-background-themetint:51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Support</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
 </tr>
 <tr style="mso-yfti-irow:13">
  <td width="123" valign="top" style="width:92.15pt;border:solid windowtext 1.0pt;
  border-top:none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span class="SpellE"><span lang="EN-US">footForce</span></span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal"><span lang="EN-US">The force on the foot<o:p></o:p></span></p>
  </td>
  <td width="170" valign="top" style="width:127.55pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US">Support<o:p></o:p></span></p>
  </td>
 </tr>
 <tr style="mso-yfti-irow:14">
  <td width="123" style="width:92.15pt;border:solid windowtext 1.0pt;border-top:
  none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  background:#D9E2F3;mso-background-themecolor:accent1;mso-background-themetint:
  51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">tick</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;background:#D9E2F3;mso-background-themecolor:
  accent1;mso-background-themetint:51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">The
  motion controller returns the reference time of the startup timing of the
  robot</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="170" style="width:127.55pt;border-top:none;border-left:none;
  border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;background:#D9E2F3;mso-background-themecolor:
  accent1;mso-background-themetint:51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Support</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
 </tr>
 <tr style="mso-yfti-irow:15">
  <td width="123" valign="top" style="width:92.15pt;border:solid windowtext 1.0pt;
  border-top:none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span class="SpellE"><span lang="EN-US">wirelessRemote</span></span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal"><span lang="EN-US">Wireless command<o:p></o:p></span></p>
  </td>
  <td width="170" valign="top" style="width:127.55pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US">Support<o:p></o:p></span></p>
  </td>
 </tr>
 <tr style="mso-yfti-irow:16;mso-yfti-lastrow:yes">
  <td width="123" valign="top" style="width:92.15pt;border:solid windowtext 1.0pt;
  border-top:none;mso-border-top-alt:solid windowtext .5pt;mso-border-alt:solid windowtext .5pt;
  background:#D9E2F3;mso-background-themecolor:accent1;mso-background-themetint:
  51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span class="SpellE"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">crc</span></span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="350" valign="top" style="width:262.25pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;background:#D9E2F3;mso-background-themecolor:
  accent1;mso-background-themetint:51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Checksum</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
  <td width="170" valign="top" style="width:127.55pt;border-top:none;border-left:
  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;
  mso-border-top-alt:solid windowtext .5pt;mso-border-left-alt:solid windowtext .5pt;
  mso-border-alt:solid windowtext .5pt;background:#D9E2F3;mso-background-themecolor:
  accent1;mso-background-themetint:51;padding:0cm 5.4pt 0cm 5.4pt">
  <p class="MsoNormal" align="center" style="text-align:center"><span lang="EN-US" style="color:black;mso-color-alt:windowtext">Support</span><span lang="EN-US"><o:p></o:p></span></p>
  </td>
 </tr>
</tbody>
</table>

### Comment:  
1.Setting sport mode is not supported through call unitree sdk.  
2.In normal mode, the robot dog will drift when stepping, It's best to develop in sport mode.  
3.Getting temperature in sport mode is not supported.  
4.Getting the current mode of the robot dog is not supported.  
