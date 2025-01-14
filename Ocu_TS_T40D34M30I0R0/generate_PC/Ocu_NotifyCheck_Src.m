[!AUTOSPACING!]
[!NOCODE!]

/*!
*   @file    Ocu_NotifyCheck_Src.m
*   @version 0.9.0
*
*   @brief   AUTOSAR Ocu Macros that generate notifications handlers
*   @details Macros that generate notifications handlers prototypes
*
*   @addtogroup ocu_driver Ocu Driver
*   @brief      Ocu HLD
*   @{
*/
/*!==================================================================================================
*   Project              : AUTOSAR 4.2 sMCAL
*   Platform             : PA
*   Peripheral           : Gtm
*   Dependencies         : none
*
*   Autosar Version      : 4.2.1
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 0.9.0
*   Build Version        : 
*
*   Copyright 2020 - 2023 NXP Semiconductors.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/


[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('OCU_NOTIFY_CHECK_SRC_M'))"!]
[!VAR "OCU_NOTIFY_CHECK_SRC_M"="'true'"!]

/* Variable storing number of Emios Modules available on the current platform */
[!VAR "numEmiosOcuModules" = "ecu:get('Ocu.EmiosInstanceCount')"!]

/* This macro generates the list of prototypes of Ocu channel notification handlers */
[!MACRO "GenerateOcuNotifications"!]
  [!CODE!]
/** @brief Prototypes of Ocu channels User Notifications */[!//
  [!ENDCODE!]  
  [!NOCODE!]
  [!VAR "MacOuterLoopCounter" = "0"!]
  [!VAR "MacInnerLoopCounter" = "0"!] 
  /* Loop through all Ocu channels and get name of Notification
  handlers for each of them. Loop the channels twice because there might be
  channels using same MacNotification function and we only want to 
  declare it as external once */
  [!SELECT "OcuChannelConfigSet"!]
  [!LOOP "OcuChannel/*"!]
    [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
    [!VAR "MacInnerLoopCounter" = "0"!]
    [!VAR "MacMatchcounter" = "0"!]
    [!IF "node:exists('OcuNotification/*[1]')"!]
        [!VAR "MacNotification" = "OcuNotification/*[1]"!]
        [!LOOP "../../OcuChannel/*"!]
            [!IF "(OcuNotification/*[1] != 'NULL_PTR') and (OcuNotification/*[1] != '"NULL"') and (OcuNotification/*[1] != 'NULL')"!]
                [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                    [!IF "($MacNotification = OcuNotification/*[1])"!]
                        [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!]
    [!IF "$MacMatchcounter = 1"!]
      [!CODE!]
extern Ocu_NotificationType [!"OcuNotification/*[1]"!](void);[!//
      [!ENDCODE!]
    [!ENDIF!]
  [!ENDLOOP!]
  [!ENDSELECT!] 
  [!ENDNOCODE!]
[!ENDMACRO!]

/* Below there are a couple of macros implementing methods for working with string arrays 
   on top of a simple string. The arrays can store a variable number of string entries,
   each string having a maximum length of 30 chars 
   Each element in the array has exactly 30 chars (which is also the plugin maximum allowed
length for EmiosOcu notification handlers) and is used to store the name of the EmiosOcu
Fault notification handler trailed till 30 chars with '*' */
[!MACRO "ArrayDeclare", "Size"!]
    [!VAR "OutMyArray" = "''"!]
    [!FOR "i" = "1" TO "$Size"!]
        [!VAR "OutMyArray" = "concat($OutMyArray, '******************************')"!]
    [!ENDFOR!]
[!ENDMACRO!]

[!MACRO "ArraySetElement", "Index", "Value"!]
    [!VAR "MacSetElement" = "$Value"!]
    /* Add trailing '*' chars until length of 30 */
    [!FOR "idx" = "string-length($Value)" TO "30"!]
      [!VAR "MacSetElement" = "concat($MacSetElement, '*')"!]
    [!ENDFOR!]
    /* Insert the value prepared for the entry in it's place in the string keeping the array */
    [!IF "$Index = 0"!]
        [!VAR "OutMyArray" = "concat($MacSetElement, substring($OutMyArray,31))"!]
    [!ELSE!] 
        [!VAR "OutMyArray" = "concat(substring($OutMyArray,1,$Index*30), $MacSetElement, substring($OutMyArray,$Index*30+31))"!]
    [!ENDIF!]
[!ENDMACRO!]

[!MACRO "ArrayGetElement", "Index"!]
    /* Get the element out the string storring the array and
    remove the trailing '*' chars */
    [!VAR "OutGetElement" = "substring-before(substring($OutMyArray,$Index*30+1,30),'*')"!]
[!ENDMACRO!]

/* This macro generates the list of prototypes of Emios Modules 
Fault Notification handlers */
[!MACRO "GenerateEmiosOcuFaultNotifications"!]
  [!NOCODE!]
  /* Declare an array storing the names of the Fault Notification handlers 
  for possibly each EmiosOcu module available on the platform. Each Fault
  Notification is limited by the plugin at max 30 chars length */
  [!CALL "ArrayDeclare", "Size" = "$numEmiosOcuModules * 4"!]
  
  /* If Fault Notification is globally enabled, loop through all Emios Modules 
  defined in the configuration. For each Module, insert the 4 Fault notification 
  handlers in the array */
  [!IF "OcuGeneral/OcuFaultSupport = 'true'"!]
    [!CODE!]

/** @brief Prototypes of Emios Modules Fault Notifications */[!//
    [!ENDCODE!]    
    [!LOOP "OcuChannelConfigSet/*/OcuEmiosOcu/*"!]
      /* Check if fault functionality is enabled for the current EmiosOcu Module */
      [!IF "OcuEmiosOcuFaultFunctionality = 'true'"!]
        [!VAR "MacEmiosOcuMod" = "substring-after(OcuEmiosOcuModule,'EmiosOcu_')"!]

        /* Check if a valid Fault Notification is defined for fault channel 0 and if yes,
        put it in the array, at corresponding position */
        [!IF "(OcuFaultChannel0Settings/OcuEmiosOcuFaultNotification0 != 'NULL_PTR') and (OcuFaultChannel0Settings/OcuEmiosOcuFaultNotification0 != '"NULL"') and (OcuFaultChannel0Settings/OcuEmiosOcuFaultNotification0 != 'NULL')"!]
          [!CALL "ArraySetElement", "Index" = "4*num:i($MacEmiosOcuMod)", "Value" = "OcuFaultChannel0Settings/OcuEmiosOcuFaultNotification0"!]
        [!ENDIF!]  

        /* Check if a valid Fault Notification is defined for fault channel 1 and if yes,
        put it in the array, at corresponding position */
        [!IF "(OcuFaultChannel1Settings/OcuEmiosOcuFaultNotification1 != 'NULL_PTR') and (OcuFaultChannel1Settings/OcuEmiosOcuFaultNotification1 != '"NULL"') and (OcuFaultChannel1Settings/OcuEmiosOcuFaultNotification1 != 'NULL')"!]
          [!CALL "ArraySetElement", "Index" = "4*num:i($MacEmiosOcuMod)+1", "Value" = "OcuFaultChannel1Settings/OcuEmiosOcuFaultNotification1"!]
        [!ENDIF!]  

        /* Check if a valid Fault Notification is defined for fault channel 2 and if yes,
        put it in the array, at corresponding position */
        [!IF "(OcuFaultChannel2Settings/OcuEmiosOcuFaultNotification2 != 'NULL_PTR') and (OcuFaultChannel2Settings/OcuEmiosOcuFaultNotification2 != '"NULL"') and (OcuFaultChannel2Settings/OcuEmiosOcuFaultNotification2 != 'NULL')"!]
          [!CALL "ArraySetElement", "Index" = "4*num:i($MacEmiosOcuMod)+2", "Value" = "OcuFaultChannel2Settings/OcuEmiosOcuFaultNotification2"!]
        [!ENDIF!]  

        /* Check if a valid Fault Notification is defined for fault channel 3 and if yes,
        put it in the array, at corresponding position */
        [!IF "(OcuFaultChannel3Settings/OcuEmiosOcuFaultNotification3 != 'NULL_PTR') and (OcuFaultChannel3Settings/OcuEmiosOcuFaultNotification3 != '"NULL"') and (OcuFaultChannel3Settings/OcuEmiosOcuFaultNotification3 != 'NULL')"!]
          [!CALL "ArraySetElement", "Index" = "4*num:i($MacEmiosOcuMod)+3", "Value" = "OcuFaultChannel3Settings/OcuEmiosOcuFaultNotification3"!]
        [!ENDIF!]  
      [!ENDIF!]
    [!ENDLOOP!]

    /* Now that we have all valid EmiosOcu fault notifications in the array, loop through array using
    inner and outer loop counters and identify the unique values, as user could have chosed identic
    names for multiple EmiosOcu Fault Notification handlers */
    [!FOR "MacOuterLoopCounter" = "0" TO "(num:i($numEmiosOcuModules)*4)-1"!]
      [!CALL "ArrayGetElement", "Index" = "$MacOuterLoopCounter"!]
      /* Skip over undefined notifications or notifications that were found to be null */
      [!IF "$OutGetElement != ''"!]
        [!VAR "MacMatchcounter" = "0"!]
        [!VAR "MacCurElement" = "$OutGetElement"!]
        [!FOR "MacInnerLoopCounter" = "$MacOuterLoopCounter+1" TO "(num:i($numEmiosOcuModules)*4)-1"!]
          [!CALL "ArrayGetElement", "Index" = "$MacInnerLoopCounter"!]
          [!IF "$MacCurElement = $OutGetElement"!]
            [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!] 
          [!ENDIF!]
        [!ENDFOR!]

        /* If no match was found with any notification following the current one in the array
        check if there is any Ocu channel using the EmiosOcu Module the current notification
        belongs to and in case it is, declare it as external */
        [!IF "$MacMatchcounter = 0"!]
          [!VAR "notifEmiosOcuMod" = "num:i($MacOuterLoopCounter div 4)"!]
          [!LOOP "OcuChannelConfigSet/*/OcuChannel/*"!]
            [!IF "contains(OcuHwIP,'EmiosOcu')"!]
              /* Get index of EmiosOcu module the channel belongs to */
              [!VAR "idxFlexModule" = "substring-after(node:ref(OcuEmiosOcuChannel)/../../../../OcuEmiosOcuModule,'EmiosOcu_')"!]
              /* Check if it's the same module with the one the Fault Notification belongs to */
              [!IF "num:i($idxFlexModule) = num:i($notifEmiosOcuMod)"!]
                [!CODE!]
extern Ocu_NotificationType [!"$MacCurElement"!](uint8 ModuleId, uint8 FaultChannel);[!//
                [!ENDCODE!]
              [!BREAK!]
              [!ENDIF!]
            [!ENDIF!]
          [!ENDLOOP!]
        [!ENDIF!]
      [!ENDIF!]
    [!ENDFOR!]
  [!ENDIF!]
  [!ENDNOCODE!]
[!ENDMACRO!]

[!ENDIF!] /* Avoid multiple inclusion ENDIF */
[!ENDNOCODE!]
