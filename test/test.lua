io.stdout:setvbuf("no")

MOAISim.openWindow( 'gwen', 800, 500 )
local layer = MOAILayer.new()
local viewport = MOAIViewport.new ()
viewport:setSize ( 800, 500 )
viewport:setScale ( 800, 500 )
layer:setViewport( viewport )

function bindMouseInput( sys )
	local x0, y0
	local function onMouseLeftEvent ( down )
		return sys:sendMouseButtonEvent( 0, down )
	end

	local function onMouseRightEvent ( down )
		return sys:sendMouseButtonEvent( 1, down )
	end

	local function onMouseMiddleEvent ( down )
		return sys:sendMouseButtonEvent( 2, down )
	end

	local function onMouseMoveEvent ( x, y )
		x, y = layer:wndToWorld( x, y )
		x, y = sys:worldToModel( x, y )
		y = - y
		local dx, dy
		if x0 then
			dx = x - x0
			dy = y - y0
		else
			dx, dy = 0,0
		end
		x0, y0 = x, y
		return sys:sendMouseMoveEvent( x, y, dx, dy )
	end

	MOAIInputMgr.device.mouseLeft:setCallback ( onMouseLeftEvent )
	MOAIInputMgr.device.mouseRight:setCallback ( onMouseRightEvent )
	MOAIInputMgr.device.pointer:setCallback ( onMouseMoveEvent )
end

MOAIRenderMgr.setBufferTable( { MOAIGfxDevice.getFrameBuffer() } )
MOAIGfxDevice.getFrameBuffer():setRenderTable( { layer } )

sys = MOAIGwenSystem.new()
skin = MOAIGwenSkinSimple.new()
sys:setSkin( skin )
sys:setLoc( -400, 250 )

sys:start()
bindMouseInput( sys )

layer:insertProp( sys )

canvas = sys:getCanvas()
canvas:setName( 'canvas-root' )

window = MOAIGwenWindowControl.new()
canvas:addChild( window )
window:setSize( 200, 200 )
window:setPos( 50, 50 )
window:setName( 'window-1' )

window2 = MOAIGwenWindowControl.new()
canvas:addChild( window2 )
window2:setSize( 200, 300 )
window2:setName( 'window-2' )

local button = MOAIGwenButton.new()
window:addChild( button )
button:setPos( 100, 50 )

for i, control in ipairs( canvas:getChildren() ) do
	print( i, control:getTypeName(), control:getName() )
end

local w = canvas:findChildByName( 'window-1' )
assert( w == window )

local w = canvas:findChildByName( 'window-2' )
assert( w == window2 )

print( window2:getBounds() )
print( window2:getInnerBounds() )
print( window2:getRenderBounds() )

-- label = MOAIGwenLabel.new()
-- canvas:addChild( label )
-- button:setText( 'Event Tester' )
-- button:addHandler( button.ON_PRESS, function( event, data ) print( 'button pressed' ) end )
