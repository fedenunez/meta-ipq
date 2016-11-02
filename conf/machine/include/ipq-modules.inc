

KERNEL_MODULE_AUTOLOAD += "dwc3"
module_autoload_dwc3 = "usbcore usb-common dwc3 phy-qcom-dwc3 phy-qca-baldur phy-qca-uniphy dwc3-ipq40xx"

KERNEL_MODULE_AUTOLOAD += "sd_mod usb-storage"
module_autoload_scsi-core = "sd_mod scsi_mod"

KERNEL_MODULE_AUTOLOAD += "fat"
module_autoload_fat = "fat vfat msdos nls_base nls_cp437 nls_iso8859-1"

KERNEL_MODULE_AUTOLOAD += "ehci-hcd"
module_autoload_ehci-hcd = "ehci-hcd ehci-platform ehci-orion ehci-atmel"

KERNEL_MODULE_AUTOLOAD += "xhci-hcd"
module_autoload_xhci-hcd = "xhci-hcd xhci-pci xhci-plat-hcd"
