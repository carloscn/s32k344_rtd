1. Example Description
    This application demonstrates the usage of a subset of Real Time Drivers that are included in this code drop. It is not part of the production code deliverables.
    The application includes an EB Tresos project that configures the LinTrcv Base Dem EcuC Lin EcuM Platform Mcu and Resource.
    1.1 The aplication software functionality
        In this example,It contains LinTrcv and Lin, Master sends a complete LIN frame (header + response) using Lpuart or Flexio.
    1.2 The aplication software functionality
            - Mcu_Init, Mcu_InitClock, Mcu_SetMode
                    Initialize the clock sources, the clock tree and to configure the clock gating of the peripherals.
            - Port_Init
                    Initialize the pins used by the application using the Port driver.
            - Spi_Init
                    Initialize the Spi driver.
            - Ae_Init
                    Initialize the Ae driver.
            - Platform_Init
                    Install the ISR for the Lpuart or Flexio
            - OsIf_Init
                    Initialize the Osif driver
            - LinTrcv_Init
                    Initialize the LinTrcv driver
            - LinTrcv_GetOpMode, LinTrcv_SetOpMode
                    Get mode and Set mode for LinTrcv module
            - Lin_43_LPUART_FLEXIO_InitInit
                    Initialize the Lin driver
            - Lin_43_LPUART_FLEXIO_InitWakeupInternal
                    Wakeup LIN channels for ASR 4.3.1
            - Lin_43_LPUART_FLEXIO_InitCheckWakeup
                    Check Lin channel wakeup
            - Lin_43_LPUART_FLEXIO_InitSendFrame
                    Send LIN frame
            - Lin_43_LPUART_FLEXIO_InitGetStatus
                    Get status of Lin
2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            XS32M2XXCVB-Q064 PCB 53099 RevX1 SCH RevA
            Silicon: Silicon S32M276 P32M276LH MKHS 0P73G CTZA2305B (Use for LINTRCV)
        2.2.2 Connections
            No pin connection required.
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
                Ex: TRESOS_DIR = C:/EB/tresos2710
            - GCC_DIR The path to the GCC instalation dir
                Ex: GCC_DIR = C:/NXP/S32DS.3.3/S32DS/build_tools/gcc_v9.2/gcc-9.2-arm32-eabi
            - PLUGINS_DIR The path to the RTD plugins directory
                Ex: PLUGINS_DIR = C:/NXP/SW32_RTD/eclipse/plugins
            Procedure:
                1. Open project_parameters.mk file in a text editor and update the variables mentioned above with the correct paths
                2. Open "Makefile" file in a text editor and add path to the Linif header directory to INCLUDE_DIRS+=
                    Ex: $(PLUGINS_DIR)/LinIf_$(AR_PKG_NAME)/include
3. Building the example application
    3.1 Generate the Tresos project of the example, execute the following command to build: make generate
        Attention warring are generate as normal:
            - The node "/AUTOSAR/TOP-LEVEL-PACKAGES/EcuM/ELEMENTS/EcuM/EcuMConfiguration/EcuMCommonConfiguration/EcuMDefaultAppMode" with value "" does not refer to nodes.
            - The node "/AUTOSAR/TOP-LEVEL-PACKAGES/EcuM/ELEMENTS/EcuM/EcuMConfiguration/EcuMCommonConfiguration/EcuMOSResource/__1" with value "" does not refer to nodes.
    3.2 Compiling the application
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To build the example, execute the following command to build: make build
            4. The object files and linker output file (main.elf) shall be generated in the /out subdirectory
    3.3 Running the application on the board
        To execute the example application load the executable file to the evaluation board using the Lauterbach debugger and the run.cmm script.
    3.4 Modifying the configuration in Tresos and generating the code
        Users may change the application configuration according to their needs.
        Procedure:
            1. Open the EB Tresos Studio GUI
            2. Open previously imported Example Application project
            3. Use the Tresos Studio GUI to modify configuration parameter values and save the changes.
            4. Select the Example Application project and click on "Generate" button to generate the configuration files.
