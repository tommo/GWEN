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
skin = MOAIGwenSkinTexturedBase.new()
skin:init( 'DefaultSkin.png' )
-- skin = MOAIGwenSkinSimple.new()

sys:setSkin( skin )
sys:setLoc( -200, 250 )

sys:start()
bindMouseInput( sys )

layer:insertProp( sys )

canvas = sys:getCanvas()
canvas:setName( 'canvas-root' )
canvas:setSize( 500, 500 )

window = canvas:addChild( MOAIGwenWindowControl.new() )
window:setSize( 100, 100 )
window:restrictToParent( false )


label = window:addChild( MOAIGwenLabel.new() )
label:setText( 'GOOD to die' )
label:setTextColorOverride( 1,0,0,1 )
label:setPos( 100, 50 )

button = window:addChild( MOAIGwenButton.new() )
button:setSize( 200, 30 )
-- button:setListener( MOAIGwenControl.EVENT_HOVER_ENTER, function() print'hover.enter' end )
-- button:setListener( MOAIGwenControl.EVENT_HOVER_EXIT, function() print'hover.exit' end )
button:setListener( MOAIGwenButton.EVENT_CLICK, function() print'click' end )
button:setListener( MOAIGwenButton.EVENT_DOWN, function() print'down' end )
button:setListener( MOAIGwenButton.EVENT_UP, function() print'up' end )

-- window:setListener( window.EVENT_CLOSE, function() print('window closed') end )
-- window:addListener( window.EVENT_CLOSE, function() print( 'window closed' ) end )
-- window:setListener( window.EVENT_CLOSE, function() print('window closed') end )
-- window:getEventHandler( 'close' ):add( obj, function() end )
-- window:setListener( window.EVENT_CLOSE)

-- window.addListener( window.EVENT_CLOSE, function() ... end )


-- local func = function() print 'button A' end
-- button:addListener( button.EVENT_CLICK, func )
-- button:addListener( button.EVENT_CLICK )
-- button.onClick:add( func )
-- button:clearListeners()

-- button:setListener( button.EVENT_CLICK, func )
-- button:removeListener( button.EVENT_CLICK )

