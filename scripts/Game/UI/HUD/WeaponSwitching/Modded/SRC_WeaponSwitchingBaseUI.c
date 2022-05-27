modded class SCR_WeaponSwitchingBaseUI: SCR_InfoDisplay {
	private ref CRSE_WeaponHolster weaponHolster;

    override protected void Init(IEntity owner) {
		super.Init(owner);
		weaponHolster = new CRSE_WeaponHolster(owner);
		weaponHolster.Init();
    }

	override protected void RemoveActionListeners() {
		super.RemoveActionListeners();
		weaponHolster.unregisterEventListener();
	}
}