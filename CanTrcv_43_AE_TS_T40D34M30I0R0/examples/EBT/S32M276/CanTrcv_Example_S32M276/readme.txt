1. Example Description
        This is a simple application to show the functionality of CANTRCV Driver:
        - Switching transceiver modes
        - Checking transmision and reception between 2 Can nodes:
            - Node A: FLEXCAN_0 is connected to AE_CAN_PHY(on-package).
            - Node B: FLEXCAN_1 is connected to an external transceiver on the board(TJA1462A).

    1.1 The application software functionality
        - Using Mcu_InitClock to initialize the clock sources, the clock tree and to configures the clock gating of the peripherals.
        - Using Port_Init to initialize pins for LPSPI interface, pins for FLEXCAN_0, FLEXCAN_1.
        - Using Spi_Init for configuration: baudrate, chip select,... of LPSPI.
        - Initialize configuration's structure of AE through Ae_Init.
        - Using CanTrcv_Init to initialize AE_CAN_PHY.
        - CanTrcv_SetOpMode to set the operation mode for Can PHY Transceiver.
        - Send a message from node B to node A.
        
2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - EVB board: XS32M2XXCVB-Q064 PCB 53099 RevX1 SCH RevA.
            - Silicon: P32M276CH MKHS 0P73G CTZA2305A
        2.2.2 Connections
            Switch following jumpers to select M276 chip:
                J187.2 to J187.3
                J105.2 to J105.3
                J104.2 to J104.3
                J82.2 to J82.3
                J89.2 to J89.3
                J126.2 to J126.3
                J127.2 to J127.3

            Switch following jumpers to select Can Transceiver chip:
                J175.2 to J175.3
                J98.2 to J98.3
                J106.2 to J106.3
                J170.2 to J170.3

            J138.3 to J138.4 to connect PTC3(FLEXCAN1_TX) to TXD of TJA1462A
            J138.7 to J138.8 to connect PTC2(FLEXCAN1_RX) to RXD of TJA1462A
            J220 to GND to switch TJA1462A to NORMAL mode(exit from STANDBY mode)
            J181.1 to J131(S32M2xx_CANH) to connect CAN_H of TJA1462A to CAN_H of AE_CAN_PHY
            J181.2 to J141(S32M2xx_CANL) to connect CAN_L of TJA1462A to CAN_L of AE_CAN_PHY
            
            Note:
                FLEXCAN_0 TX/RX pins are automatically connected to TXD/RXD of AE_CAN_PHY in chip package.
        2.2.3 Debugger
            The debugger must be connected to JTAG Cortex Debug connector.
    2.2 Software installation
        2.2.1 Tresos Project Installation
            The following procedure requires that the user has EB Tresos Studio installed and it is only needed for viewing, updating and generating the driver's configuration.
            Procedure:
                1. Make sure that all RTD plugins are already installed in the Tresos Studio plugins directory
                2. Open Tresos Studio
                3. Import example application project
                    a. Click on "File" and select "Import"
                    b. Select "Existing Projects into Workspace" and click on "Next" button
                    c. Select "Select root directory" and click on "Browse"
                    d. Select the location of the [project] folder in the installed example application package folder
                    e. Optional* - Select "Copy projects into workspace" 
                    f. Click on "Finish" button
        2.2.2 Example configuration
            The following procedure requires that the user has EB Tresos Studio installed and the toolchains versions specified in the Release Notes.
            The toolchain that will be used needs to be installed for correct operation and the path to the installation location shall be added into the system environment variable(s):
            - TRESOS_DIR the installation path of Electrobit Tresos (used for generating the project from command line)
                Ex: TRESOS_DIR = C:/EB/tresos29
            - GCC_DIR The path to the GCC installation dir
                Ex: GCC_DIR = C:/NXP/S32DS.3.5/S32DS/build_tools/gcc_v10.2/gcc-10.2-arm32-eabi
            - PLUGINS_DIR The path to the Tresos plugins directory
                Ex: PLUGINS_DIR = C:/NXP/SW32_RTD/eclipse/plugins
            - T32_DIR The path to the T32 directory
                Ex: T32_DIR = C:/T32

            Procedure:
                1. Open project_parameters.mk file in a text editor and update the variables mentioned above with the correct paths
3. Building the example application
    3.1 Generating the Tresos project
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To generate the Tresos project of the example, execute the following command to build: make generate
            4. The output files of the generation shall be generated in the /generate subdirectory
            Attention Warrnings are generated as normal:
                - The node "/AUTOSAR/TOP-LEVEL-PACKAGES/EcuM/ELEMENTS/EcuM/EcuMConfiguration/EcuMCommonConfiguration/EcuMOSResource/__1" with value "" does not refer to nodes.
                - The node "/AUTOSAR/TOP-LEVEL-PACKAGES/EcuM/ELEMENTS/EcuM/EcuMConfiguration/EcuMCommonConfiguration/EcuMDefaultAppMode" with value "" does not refer to nodes.
                - The node "/AUTOSAR/TOP-LEVEL-PACKAGES/Can_43_FLEXCAN/ELEMENTS/Can/CanGeneral/CanSupportTTCANRef" with value "" does not refer to nodes.
    3.2 Compiling the application
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To build the example, execute the following command to build: make build
            4. The object files and linker output file (main.elf) shall be generated in the /out subdirectory
    3.3 Running the application on the board
        To execute the example application from your command line execute make run. For executing the script in a T32 window already open the paths from run.cmm need to be changed relative to the debug folder instead of the example root folder.
    3.4 Modifying the configuration in Tresos and generating the code
        Users may change the application configuration according to their needs.
        Procedure:
            1. Open the EB Tresos Studio GUI
            2. Open previously imported Example Application project
            3. Use the Tresos Studio GUI to modify configuration parameter values and save the changes.
            4. Select the Example Application project and click on "Generate" button to generate the configuration files.
